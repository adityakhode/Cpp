#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

using namespace std;

class UnitMaster
{
    public:
        void create();
        void insert(const vector<string>& params);
        void addData(const string& filename);
        void dataAvailable();
        void getPartNo(int part_no) const;
        void getPartName(int part_no) const;
        void getPartNoList() const;
};

class PartyMaster
{   
    public:
        void create();
        void insert(string supplier_code, string party_name, string party_address);
        void addData(string filename);
        void dataAvailable();
        void getSupplierCodeAndNameList() const;
};

class ResultMaster
{
    public:
        void create(string tablename);
        void insert(string tablename, const vector<string>& params);
        void addData(string tablename, string filename);
        void getDetails(string tablename, string TcNo) const;
        void createAll();
        void printDetails(string party_name, string party_address) const;
};

#endif // DATABASE_H
