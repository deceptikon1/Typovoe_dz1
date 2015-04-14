// Copyright 2015 <Sergey Fedotov>
#include "./all.h"

class myexception : public std::exception {
 public:
    explicit myexception(const char *str) : std::exception(str){}
};
