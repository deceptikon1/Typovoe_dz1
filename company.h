// Copyright 2015 <Sergey Fedotov>
#pragma once

#include <string>
#include <list>
#include "./worker.h"

class Company {
    std::list < Worker > list;
    string name;
    bool goodDepart;

 public:
    Company();
    Company(const string& name, bool goodDepart);
    Company(const Company& buf);
    ~Company();

    void addWorker(const Worker& buf);

    void delWorker(const Worker& wrk);
    void delWorkerNum(int i);

    void setCompany(const string& name, bool goodDepart);
    void setDepartName(const string& name);
    void setGoodDepart(bool goodDepart);

    int getWorkersNum()const;
    bool getGoodDepart()const;
    const string& getDepartName()const;
    const Worker& getWorker(int i)const;

    bool hasWorker(const Worker& wrk)const;
    const Company operator +(const Worker& buf2)const;
    const Company& operator =(const Company& buf);
    bool operator ==(const Company& buf)const;
    friend ostream& operator <<(ostream& stream, const Company& buf);
};
