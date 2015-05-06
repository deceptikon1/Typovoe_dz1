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
using std::to_string;


class Worker {
    string name;
    int age;
    int salary;
    int exp;
    bool goodWorker;

 public:
    Worker();
    Worker(const string& name, int age, int salary,
        int exp, bool goodWorker);
    Worker(const string& name, int age);
    Worker(const Worker& buf);

    ~Worker();

    void setWorker(const string& name, int age,
        int salary, int exp,
        bool goodWorker);
    void setName(const string& name);
    void setAge(int age);
    void setSalary(int salary);

    const string& getName()const;
    int getAge()const;
    int getSalary()const;

    friend ostream & operator <<(ostream& stream, const Worker& buf);
    const Worker& operator =(const Worker& buf);
    bool operator==(const Worker& buf)const;
};
