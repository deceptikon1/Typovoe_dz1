// Copyright 2015 <Sergey Fedotov>
#pragma warning(disable:4996)
#include <string>
#include <list>
#include "./all.h"
#include "myexception.cpp"

company::company() : list() {
    string name = string();
    int workers = 0;
    bool gooddepart = false;
}

company::company(const string& name, const bool& gooddepart) :list() {
    this->name = name;
    int workers = 0;
    this->gooddepart = gooddepart;
}

company::company(const company& buf) {
    this->name = buf.name;
    this->gooddepart = buf.gooddepart;
}

company::~company() {
    string name = string();
    int workers = 0;
    bool gooddepart = false;
}

void company::addworker(const Worker & buf) {
    if (!this->hasworker(buf)) {
    workers++;
     list.insert(list.end(), buf);
    } else {
      throw myexception("Same worker has already exist");
     }
}

void company::delworker(const Worker& wrk) {
    if (!this->hasworker(wrk)) {
        throw myexception("Error - worker not found");
    } else {
        Worker iter = this->find(wrk);
        list.remove(iter);
        workers--;
    }
}


void company::delworkernum(const int& q) {
    if ((q > workers) || (q < 1)) {
        throw myexception("Error - worker not found");
    } else {
        Worker iter = this->getworker(q);
        list.remove(iter);
        workers--;
    }
}

void company::setcompany(const string& name, const bool& gooddepart) {
    this->name = name;
    this->gooddepart = gooddepart;
}

void company::setdepartname(const string& name) {
    this->name = name;
}

void company::setgooddepart(const bool& gooddepart) {
    this->gooddepart = gooddepart;
}

const string& company::getdepartname() {
    return name;
}

const int& company::getworkersnum() {
    return workers;
}

const bool& company::getgooddepart() {
    return gooddepart;
}

const Worker& company::getworker(const int& q) {
    std::list<Worker>::iterator iter = list.begin();
    if ((q > workers) || (q < 1)) {
        throw myexception("Error - worker not found");
    } else {
        for (int i = 0; i < q - 1; i++)
            iter++;
        return *iter;
    }
}

const Worker& company::find(const Worker& wrk) {
    std::list<Worker>::iterator iter = list.begin();
        while (iter != list.end()) {
            if (*iter == wrk) {
                return *iter;
            }
            iter++;
        }
        return *list.end();
}

const bool company::hasworker(const Worker& wrk) {
    std::list<Worker>::iterator iter = list.begin();
    while (iter != list.end()) {
        if (*iter == wrk) {
            return true;
        }
        iter++;
    }
    return false;
}



company & operator +(const Worker & buf1, const Worker & buf2) {
    company *one;
    one = new company("New company ", true);
    one->addworker(buf1);
    one->addworker(buf2);

    return *one;
}

company & company::operator +(const Worker & buf2) {
    this->addworker(buf2);
    return *this;
}

ostream & operator <<(ostream & streams, company& str)  {
    streams << "Depart " << str.name<< ", work quality - ";
    if (str.gooddepart)
        streams << "good" << endl<< endl;
    else
        streams << "bad" << endl<< endl;

    for ( list<Worker>::iterator i = str.list.begin();
        i != str.list.end(); i++) {
        streams << *i;
    }
    return streams;
}

const bool& company::operator ==(const company& buf) {
    if (this->name == buf.name && this->gooddepart == buf.gooddepart)
        return true;
    else
        return false;
}

const company& company::operator =(const company& buf) {
    name = buf.name;
    gooddepart = buf.gooddepart;
    return *this;
}
