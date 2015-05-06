// Copyright 2015 <Sergey Fedotov>
#pragma warning(disable:4996)
#include <string>
#include "./all.h"

Worker::Worker() {
    this->name = string();
    int age = 0;
    int exp = 0;
    int salary = 0;
    bool goodWorker = false;
}

Worker::Worker(const string& name, int age,
    int exp, int salary, bool goodWorker) {
    this->name = name;
    this->age = age;
    this->exp = exp;
    this->salary = salary;
    this->goodWorker = goodWorker;
}

Worker::Worker(const string& name, int age) {
    this->name = name;
    this->age = age;
    exp = 0;
    salary = 0;
    goodWorker = false;
}


Worker::~Worker() {}

Worker::Worker(const Worker& buf) {
    this->name = buf.name;
    this->age = buf.age;
    this->exp = buf.exp;
    this->salary = buf.salary;
    this->goodWorker = buf.goodWorker;
}

void Worker::setWorker(const string& name, int age,
    int exp, int salary, bool goodWorker) {
    this->name = name;
    this->age = age;
    this->exp = exp;
    this->salary = salary;
    this->goodWorker = goodWorker;
}

void Worker::setName(const string& name) {
    this->name = name;
}

void Worker::setAge(int age) {
    this->age = age;
}

void Worker::setSalary(int salary) {
    this->salary = salary;
}

int Worker::getAge()const {
    return age;
}

int Worker::getSalary()const {
    return salary;
}

const string& Worker::getName()const {
    return name;
}

const Worker& Worker::operator =(const Worker & buf) {
    if (this != &buf) {
        name = buf.name;
        age = buf.age;
        salary = buf.salary;
        goodWorker = buf.goodWorker;
    }
    return *this;
}

ostream & operator <<(ostream & stream, const Worker& buf) {
    stream << "Worker " << buf.name << ",age " << buf.age
        << ",salary " << buf.exp << ",exp " << buf.salary << ",quality ";
    if (buf.goodWorker)
        stream << "good" << endl;
    else
        stream << "bad" << endl;
    return stream;
}

bool Worker::operator ==(const Worker & buf)const {
    return this->name == buf.name && this->age == buf.age
        && this->salary == buf.salary &&
        this->exp == buf.exp &&
        this->goodWorker == buf.goodWorker;
}
