// database.h
#ifndef DATABASE_H
#define DATABASE_H

class UnitMaster
    {
        void create();
        void insert(const std::vector<std::string>& params);
        void addData(string filename);
        void dataAvailable();
        void getPartNo(int part_no);
        void getPartName(int part_no);
        void getPartNoList();
    }

class PartyMaster
    {
        void create();
        void insert(string supplier_code, string party_name, string party_address);
        void addData(string filename);
        void dataAvailable();
        void getSupplierCodeAndNameList();
    }

class UnitMaster
    {
        void create(string tablename);
        void insert(string tablename, const std::vector<std::string>& params);
        void addData(string tablename, string filename);
        void getDetails(string tablename, string TcNo);
        void createAll();
        void  printDetails(string party_name, string party_address);
    }