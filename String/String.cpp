#include <string.h>

#include "String.hpp"

String::String(const char *a) : len(strlen(a))
{
    str = new char[len + 1];
    int i;
    for (i = 0; a[i]; i++)
        str[i] = a[i];
    str[i] = 0;
}

String::String(const String& a) : len(a.len)
{
    str = new char[a.len + 1];
    int i;
    for (i = 0; i < a.len; i++)
        str[i] = a.str[i];
    str[i] = 0;
}

const String& String::operator=(const String& a)
{
    len = a.len;
    if (str)
        delete [] str;
    
    str = new char[len + 1];
    int i;
    for (i = 0; i < a.len; i++)
        str[i] = a.str[i];
    str[i] = 0;
    return *this;
}