// Copyright 2015 <Sergey Fedotov>
#pragma once
#include <exception>
#include <string>
#include "./worker.h"

class NotFound : public std::exception {
    string str;
 public:
    explicit NotFound(const Worker & wrk);
    const char* what() const throw();
};

class Exist : public exception {
    string str;
 public:
    explicit Exist(const Worker & wrk);
    const char* what() const throw();
};

class NumNotFound : public exception {
    string str;
 public:
    explicit NumNotFound(int i);
    const char* what() const throw();
};
