#pragma once 

#include <string>
using std::string;

long string_to_long(const string &str)
{
    std::string::size_type sz;
    return std::stol(str, &sz);
}