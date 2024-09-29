#include "database.h"
#include <vector>
#include<string>

using namespace std;
int main()
    {
        UnitMaster unitMaster;
        unitMaster.create();
        std::vector<std::string> param = {
        "1",                        // PartNo (INT)
        "Part Name Example",       // PartName (VARCHAR)
        "0",                        // SingleDualOp (SMALLINT)
        "Threading Type",          // Threading (VARCHAR)
        "10",                       // Lengths (SMALLINT)
        "Y",                        // ThreadingGoNoGo (CHAR)
        "5",                        // NoLockNuts (SMALLINT)
        "1.5",                      // NutThickness (FLOAT)
        "2.0",                      // NutFlatAcross (FLOAT)
        "0.5",                      // PinProtrusion (FLOAT)
        "Cable Type",              // CabelType (VARCHAR)
        "20",                       // CableLength (SMALLINT)
        "Connector 1",             // Connector1 (VARCHAR)
        "Connector 2",             // Connector2 (VARCHAR)
        "100.0",                   // UpperResistance (FLOAT)
        "50.0",                    // LowerResistance (FLOAT)
        "12.0",                    // UpperVoltage (FLOAT)
        "5.0",                     // LowerVoltage (FLOAT)
        "10.0",                    // UpperInductance (FLOAT)
        "1.0",                     // LowerInductance (FLOAT)
        "60.0"                     // FREQUENCY (FLOAT)
    };
        unitMaster.insert(param);
        unitMaster.addData("/home/adix/Documents/Cpp/4_MPUTESTER/refrenceMaterial/unitMaster.xlsx");
    }