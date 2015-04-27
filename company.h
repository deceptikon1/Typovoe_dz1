// Copyright 2015 <Sergey Fedotov>
#pragma once

#include <string>
#include <list>
#include "./worker.h"

class company {
    std::list < Worker > list;
    string name;
    bool gooddepart;
    company *one;

 public:
    company();
    company(const string& name, const bool& gooddepart);
    company(const company& buf);

    ~company();

    void addworker(const Worker& buf);

    void delworker(const Worker& wrk);
    void delworkernum(int i);

    void setcompany(const string& name, const bool& gooddepart);
    void setdepartname(const string& name);
    void setgooddepart(const bool& gooddepart);

    int getworkersnum()const;
    const bool& getgooddepart();
    const string& getdepartname();
    const Worker& getworker(int i);

    const bool hasworker(const Worker& wrk);

    friend company & operator +(const Worker& buf1, const  Worker& buf2);
    const company & operator +(const Worker& buf2);
    const company& operator =(const company& buf);
    const bool& operator ==(const company& buf);
    friend ostream & operator <<(ostream & stream, const company& buf);
};
