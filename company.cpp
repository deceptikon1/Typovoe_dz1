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

company::~company() {}

void company::addworker(const Worker & buf) {
    if (!this->hasworker(buf)) {
     list.push_back(buf);
    } else {
      throw exist(buf);
     }
}

void company::delworker(const Worker& wrk) {
    if (!this->hasworker(wrk)) {
        throw notfound(wrk);
    } else {
        std::list<Worker>::iterator iter =
             std::find(list.begin(), list.end(), wrk);
        list.erase(iter);
    }
}


void company::delworkernum(int q) {
    if ((q > list.size()) || (q < 0)) {
        throw numnotfound(q);
    } else {
        Worker iter = this->getworker(q);
        list.remove(iter);
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


int company::getworkersnum()const {
    return list.size();
}

const bool& company::getgooddepart() {
    return gooddepart;
}

const Worker& company::getworker(int q) {
    std::list<Worker>::iterator iter = list.begin();
    if ((q > list.size()) || (q < 0)) {
        throw numnotfound(q);
    } else {
        std::advance(iter, q);
           return *iter;
    }
}


const bool company::hasworker(const Worker& wrk) {
    std::list<Worker>::iterator iter = std::find(list.begin(), list.end(), wrk);
    return (iter != list.end()) ? true : false;
}



company & operator +(const Worker & buf1, const Worker & buf2) {
    company *one;
    one = new company("New company ", true);
    one->addworker(buf1);
    one->addworker(buf2);
    return *one;
}

const company & company::operator +(const Worker & buf2) {
    this->addworker(buf2);
    return *this;
}

ostream & operator <<(ostream & streams, const company& str)  {
    streams << "Depart " << str.name<< ", work quality - ";
    if (str.gooddepart)
        streams << "good" << endl<< endl;
    else
        streams << "bad" << endl<< endl;

    for (list<Worker>::const_iterator i = str.list.begin();
        i != str.list.end(); i++) {
        streams << *i;
    }
    return streams;
}

const bool& company::operator ==(const company& buf) {
        return (this->name == buf.name &&
        this->gooddepart == buf.gooddepart) ? true : false;
}

const company& company::operator =(const company& buf) {
    name = buf.name;
    gooddepart = buf.gooddepart;
    return *this;
}
