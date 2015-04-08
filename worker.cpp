// Copyright 2015 <Sergey Fedotov>
#pragma warning(disable:4996)
#include <string>
#include "libs/all.h"

Worker::Worker() {
    this->name = string();
    int age = 0;
    int exp = 0;
    int salary = 0;
    bool goodworker = false;
}

Worker::Worker(const string& name, const int& age,
    const int& exp, const int& salary, const bool& goodworker) {
    this->name = name;
    this->age = age;
    this->exp = exp;
    this->salary = salary;
    this->goodworker = goodworker;
}

Worker::Worker(const string& name, const int& age) {
    this->name = name;
    this->age = age;
    exp = 0;
    salary = 0;
    goodworker = false;
}


Worker::~Worker() {
    this->name = string();
    int age = 0;
    int exp = 0;
    int salary = 0;
    bool goodworker = false;
}

Worker::Worker(const Worker& buf) {
    this->name = buf.name;
    this->age = buf.age;
    this->exp = buf.exp;
    this->salary = buf.salary;
    this->goodworker = buf.goodworker;
}

void Worker::setworker(const string& name, const int& age,
    const int& exp, const int& salary, const bool& goodworker) {
    this->name = name;
    this->age = age;
    this->exp = exp;
    this->salary = salary;
    this->goodworker = goodworker;
}

void Worker::setname(const string& name) {
    this->name = name;
}

void Worker::setage(const int& age) {
    this->age = age;
}

void Worker::setsalary(const int& salary) {
    this->salary = salary;
}

const int& Worker::getage() {
    return age;
}

const int& Worker::getsalary() {
    return salary;
}

const string& Worker::getname() {
    return name;
}

const Worker& Worker::operator =(const Worker & buf) {
    name = buf.name;
    age = buf.age;
    salary = buf.salary;
    goodworker = buf.goodworker;
    return *this;
}

ostream & operator <<(ostream & stream, const Worker& buf) {
    stream << "Worker " << buf.name << ",age " << buf.age
    << ",salary " << buf.exp << ",exp " << buf.salary << ",quality ";
    if (buf.goodworker)
        stream << "good" << endl;
    else
        stream << "bad" << endl;
    return stream;
}

const bool& Worker::operator ==(const Worker & buf) {
     if (this->name == buf.name && this->age == buf.age
         && this->salary == buf.salary &&
         this->exp == buf.exp && this->goodworker == buf.goodworker)
         return true;
     else
         return false;
}
