// Copyright 2015 <Sergey Fedotov>
#include <string>
#include "./all.h"


NotFound::NotFound(const Worker & wrk) {
         str = "Worker : " + wrk.getName() + ", " +
             to_string(wrk.getAge()) +
             " years, " + "salary - " +
             to_string(wrk.getSalary()) +"  NOT FOUND";
     }
     const char* NotFound::what() const throw() {
        return str.c_str();
     }


Exist::Exist(const Worker & wrk) {
        str = "Worker : " + wrk.getName() + ", " +
            to_string(wrk.getAge()) +
            " years, " + "salary - " +
            to_string(wrk.getSalary()) + "  HAVE ALREADY EXIST";
    }
    const char* Exist::what() const throw() {
        return str.c_str();
    }



NumNotFound::NumNotFound(int i) {
         str = "Worker, who number - " + to_string(i) + " NOT FOUND";
     }
    const char* NumNotFound::what() const throw() {
         return str.c_str();
     }
