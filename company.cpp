// Copyright 2015 <Sergey Fedotov>
#pragma warning(disable:4996)
#include <string>
#include <list>
#include "./all.h"

Company::Company() : list() {
    string name = string();
    int workers = 0;
    bool goodDepart = false;
}



Company::Company(const Company& a) : list(a.list),
name(a.name), goodDepart(a.goodDepart) {}

Company::Company(const string& name, bool goodDepart) :list() {
    this->name = name;
    int workers = 0;
    this->goodDepart = goodDepart;
}


Company::~Company() {}

void Company::addWorker(const Worker& buf) {
    if (!this->hasWorker(buf)) {
        list.push_back(buf);
    } else {
        throw Exist(buf);
    }
}

void Company::delWorker(const Worker& wrk) {
    std::list<Worker>::iterator iter =
        std::find(list.begin(), list.end(), wrk);
    if (iter == list.end())
        throw NotFound(wrk);
    list.erase(iter);
}

void Company::delWorkerNum(int q) {
    if ((q > list.size()) || (q < 0)) {
        throw NumNotFound(q);
    } else {
        Worker iter = this->getWorker(q);
        list.remove(iter);
    }
}

void Company::setCompany(const string& name, bool goodDepart) {
    this->name = name;
    this->goodDepart = goodDepart;
}

void Company::setDepartName(const string& name) {
    this->name = name;
}

void Company::setGoodDepart(bool goodDepart) {
    this->goodDepart = goodDepart;
}

const string& Company::getDepartName()const {
    return name;
}


int Company::getWorkersNum()const {
    return list.size();
}

bool Company::getGoodDepart()const {
    return goodDepart;
}

const Worker& Company::getWorker(int q)const {
    std::list<Worker>::const_iterator iter = list.cbegin();
    if ((q > list.size()) || (q < 0)) {
        throw NumNotFound(q);
    } else {
        std::advance(iter, q);
        return *iter;
    }
}


bool Company::hasWorker(const Worker& wrk)const {
    std::list<Worker>::const_iterator iter =
		std::find(list.cbegin(), list.cend(), wrk);
    return iter != list.cend();
}


const Company Company::operator +(const Worker& buf2)const {
    Company company(*this);
    company.addWorker(buf2);
    return company;
}

ostream& operator <<(ostream& streams, const Company& str)  {
    streams << "Depart " << str.name << ", work quality - ";
    if (str.goodDepart)
        streams << "good" << endl << endl;
    else
        streams << "bad" << endl << endl;

    for (list<Worker>::const_iterator i = str.list.begin();
        i != str.list.end(); i++) {
        streams << *i;
    }
    return streams;
}

bool Company::operator ==(const Company& buf)const {
    return this->name == buf.name &&
        this->goodDepart == buf.goodDepart;
}

const Company& Company::operator =(const Company& buf) {
    if (this != &buf) {
    name = buf.name;
    goodDepart = buf.goodDepart;
    }
    return *this;
}
