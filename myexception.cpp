// Copyright 2015 <Sergey Fedotov>
#include "libs/all.h"

class myexception : public std::exception {
 public:
    myexception(const char *str) : std::exception(str){}
};
