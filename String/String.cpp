#include <string.h>

#include "String.hpp"

String::String(const char *a) : len(strlen(a))
{
    str = new char[len];
    int i;
    for (i = 0; a[i]; i++)
        str[i] = a[i];
    str[i] = 0;
}

String::String(const String& a) : len(a.len)
{
    str = new char[a.len];
    int i;
    for (i = 0; a.len; i++)
        str[i] = a.str[i];
    str[i] = 0;
}