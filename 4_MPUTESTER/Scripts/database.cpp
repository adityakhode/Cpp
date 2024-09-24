#include "database.h"
#include <iostream>
#include <filesystem>

using namespace std;

void UnitMaster::create()
{
    filesystem::path curPath = filesystem::current_path();
    cout << "Current Path: " << curPath << endl;
    
    filesystem::path databasePath = curPath / "Database";
    cout << "Database Path: " << databasePath << endl;
    
    if (!filesystem::exists(databasePath)) {
        filesystem::create_directories(databasePath);
    }
}
