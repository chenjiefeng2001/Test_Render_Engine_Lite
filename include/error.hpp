#pragma once
#include <ios>
#include <mutex>
#include <system_error>
#include <string>

#ifndef ERROR
#define ERROR
template <class T>
class ERROR_MSG{
    std::string ERROR_STR;
    int flags;
};

#endif