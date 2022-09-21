#ifndef TYPENAME_H
#define TYPENAME_H

#include <string>

#include "../Rational_number/Rational_number.h"
#include "../StringInt/StringInt.h"

template <typename T>
std::string get_type_name()
{
    return typeid(T).name();
}

template <>
std::string get_type_name<double>()
{
    return "double";
}

template <>
std::string get_type_name<float>()
{
    return "float";
}

template <>
std::string get_type_name<int>()
{
    return "int";
}

template <>
std::string get_type_name<Rational_number>()
{
    return "rational";
}

template <>
std::string get_type_name<StringInt>()
{
    return "string_int";
}

#endif // TYPENAME_H
