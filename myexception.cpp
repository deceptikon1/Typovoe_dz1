// Copyright 2015 <Sergey Fedotov>
#include <string>
#include "./all.h"

class notfound : public std::exception {
    string str;
 public:
    explicit notfound(const Worker & wrk) {
         str = "Worker : " + wrk.getname() + ", " +
             to_string(wrk.getage()) +
             " years, " + "salary - " +
             to_string(wrk.getsalary()) +"  NOT FOUND";
     }
     const char* what() const throw(){
        return str.c_str();
     }
};

class exist : public exception {
    string str;
 public:
    explicit exist(const Worker & wrk) {
        str = "Worker : " + wrk.getname() + ", " +
            to_string(wrk.getage()) +
            " years, " + "salary - " +
            to_string(wrk.getsalary()) + "  HAVE ALREADY EXIST";
    }
    const char* what() const throw(){
        return str.c_str();
    }
};

class numnotfound : public exception {
    string str;
 public:
    explicit numnotfound(int i) {
         str = "Worker, who number - " + to_string(i) + " NOT FOUND";
     }
     const char* what() const throw(){
         return str.c_str();
     }
};
