// Copyright 2015 <Sergey Fedotov>
#pragma once
#include <string>
using std::cout;
using std::string;
using std::ostream;
using std::endl;
using std::exception;
using std::cerr;
using std::list;


class Worker {
    string name;
    int age;
    int salary;
    int exp;
    bool goodworker;

 public:
    Worker();
    Worker(const string& name, const int& age, const int& salary,
           const int& exp, const bool& goodworker);
    Worker(const string& name, const int& age);
    Worker(const Worker& buf);

    ~Worker();

    void setworker(const string& name, const int& age,
                   const int& salary, const int& exp,
                   const bool& goodworker);
    void setname(const string& name);
    void setage(const int& age);
    void setsalary(const int& salary);

    const string& getname();
    const int& getage();
    const int& getsalary();

    friend ostream & operator <<(ostream& stream, const Worker& buf);
    const Worker& operator =(const Worker& buf);
    const bool& operator==(const Worker& buf);
};
