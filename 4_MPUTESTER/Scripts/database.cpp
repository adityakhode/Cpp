#include "database.h"
#include <iostream>
#include<string>
#include<vector>
#include <sqlite3.h>
#include <filesystem>
#include <xlsxio_read.h>

using namespace std;

void UnitMaster::create()
    {
        filesystem::path curPath = filesystem::current_path();
        cout << "Current Path: " << curPath << endl;
    
        filesystem::path databasePath = curPath / "Database";
        cout << "Database Path: " << databasePath << endl;
    
        if (!filesystem::exists(databasePath)) 
            {
                if(filesystem::create_directories(databasePath))
                    {
                        cout << "Database Path Created " << endl;
                    }
                else   
                    {
                        cout << "File Creation Error " << endl;
                    }
            }
        else
            {
                cout << "Database Path already exist " << endl;
            }
        filesystem::path dbPath = databasePath / "unitMaster.db";

        sqlite3* db;
        int exit = sqlite3_open(dbPath.string().c_str(), &db);
        if (exit) 
            {
                cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
                return;
            }

        // SQL command to create the UnitMaster table
        const char* createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS UnitMaster (
            PartNo INT PRIMARY KEY,
            PartName VARCHAR,
            SingleDualOp SMALLINT,
            Threading VARCHAR,
            Lengths SMALLINT,
            ThreadingGoNoGo CHAR,
            NoLockNuts SMALLINT,
            NutThickness FLOAT,
            NutFlatAcross FLOAT,
            PinProtrusion FLOAT,
            CabelType VARCHAR,
            CableLength SMALLINT,
            Connector1 VARCHAR,
            Connector2 VARCHAR,
            UpperResistance FLOAT,
            LowerResistance FLOAT,
            UpperVoltage FLOAT,
            LowerVoltage FLOAT,
            UpperInductance FLOAT,
            LowerInductance FLOAT,
            FREQUENCY FLOAT
        );
        )";

        // Execute the SQL command
        char* errorMessage = nullptr;
        exit = sqlite3_exec(db, createTableQuery, nullptr, 0, &errorMessage);
        if (exit != SQLITE_OK) 
            {
                cerr << "SQL Error: " << errorMessage << endl;
                sqlite3_free(errorMessage);
            }

        // Close the database connection
        sqlite3_close(db);
}

void UnitMaster::insert(const vector<string>& params)
    {
        UnitMaster::create();
        if (params.size() == 21)
            {
                filesystem::path dbPath = filesystem::current_path() / "Database" / "unitMaster.db";
                sqlite3* db;
                int exit = sqlite3_open(dbPath.string().c_str(), &db);
                if (exit) 
                    {
                    cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
                    return;
                    }

                const char* insertQuery = R"(
                INSERT INTO "UnitMaster" (
                "PartNo", "PartName", "SingleDualOp", "Threading", "Lengths", "ThreadingGoNoGo",
                "NoLockNuts", "NutThickness", "NutFlatAcross", "PinProtrusion", "CabelType",
                "CableLength", "Connector1", "Connector2", "UpperResistance", "LowerResistance",
                "UpperVoltage", "LowerVoltage", "UpperInductance", "LowerInductance", "FREQUENCY"
                )
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);
                )";

                sqlite3_stmt* stmt;
                exit = sqlite3_prepare_v2(db, insertQuery, -1, &stmt, nullptr);

                if (exit != SQLITE_OK)
                    {
                        cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
                        sqlite3_close(db);
                        return;
                    }

                // Bind parameters
                for (size_t i = 0; i < params.size(); ++i) 
                    {
                        if (i == 0)
                            {
                                sqlite3_bind_int(stmt, i + 1, stoi(params[i])); // PartNo (INT)
                            }
                        else if (i == 6 || i == 7 || i == 8 || i == 9 || i == 11 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 20) 
                            {
                                sqlite3_bind_int(stmt, i + 1, stoi(params[i])); // Other SMALLINTs
                            }
                        else if (i == 7 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 20) 
                            {
                                sqlite3_bind_double(stmt, i + 1, stod(params[i])); // FLOAT values
                            } 
                        else
                            {
                                sqlite3_bind_text(stmt, i + 1, params[i].c_str(), -1, SQLITE_TRANSIENT); // VARCHARs and CHARs
                            }
                    }

                // Execute the statement
                exit = sqlite3_step(stmt);
                if (exit != SQLITE_DONE)
                    {
                        cerr << "Error executing statement: " << sqlite3_errmsg(db) << endl;
                    }

                // Finalize and close
                sqlite3_finalize(stmt);
                sqlite3_close(db);
            }
        else   
            {
                cout << "Wrong no of Paramatres in file" << endl;
            }
    }

void UnitMaster::addData(const string& filename) 
{
    // Drop existing table
    filesystem::path dbPath = filesystem::current_path() / "Database" / "unitMaster.db";
    sqlite3* db;
    int exit = sqlite3_open(dbPath.string().c_str(), &db);
    if (exit)
    {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        return;
    }

    const char* dropTableQuery = "DROP TABLE IF EXISTS UnitMaster;";
    exit = sqlite3_exec(db, dropTableQuery, nullptr, 0, nullptr);
    if (exit != SQLITE_OK)
    {
        cerr << "Error dropping table: " << sqlite3_errmsg(db) << endl;
    }

    sqlite3_close(db);

    // Create new table
    UnitMaster::create();

    // Open the Excel file
    xlsxioreader xlsxioread = xlsxioread_open(filename.c_str());
    if (!xlsxioread)
    {
        cerr << "Error opening Excel file." << endl;
        return;
    }

    // Open the desired sheet
    xlsxioreadersheet sheet = xlsxioread_sheet_open(xlsxioread, "Sheet1", 0); // Use 0 for default flags
    if (!sheet)
    {
        cerr << "Error opening sheet." << endl;
        return;
    }

    // Read rows from Excel file
    while (xlsxioread_sheet_next_row(sheet)) // Correct function
    {
        vector<string> row;

        while (true)
        {
            char* value = xlsxioread_sheet_next_cell(sheet); // Get the cell value directly
            if (value) // If value is not null
            {
                row.push_back(value);
                free(value); // Free memory for cell value
            }
            else 
            {
                break; // End of row
            }
        }

        // Insert the row into the database
        insert(row);
    }

    // Close the sheet and the Excel reader
    xlsxioread_sheet_close(sheet);
    xlsxioread_close(xlsxioread);
}
