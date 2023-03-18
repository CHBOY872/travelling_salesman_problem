#include <string.h>

#include "String.hpp"

String::String(const char *a) : len(strlen(a)), size(len + 1)
{
    str = new char[size];
    int i;
    for (i = 0; a[i]; i++)
        str[i] = a[i];
    str[i] = 0;
}

String::String(const String& a) : len(a.len), size(len + 1)
{
    str = new char[size];
    int i;
    for (i = 0; a.str[i]; i++)
        str[i] = a.str[i];
    str[i] = 0;
}

const String& String::operator=(const String& a)
{
    if (this == &a)
        return *this;

    len = a.len;

    if (size < a.len)
    {
        if (str)
            delete [] str;
        size = len + 1;
        str = new char[size];
    }

    int i;
    for (i = 0; a.str[i]; i++)
        str[i] = a.str[i];
    str[i] = 0;
    
    return *this;
}