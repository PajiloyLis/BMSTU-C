#include "my_string.h"

const char *my_strpbrk(const char *str, const char *sym)
{
    const char *p = NULL;
    for (const char *c_1 = str; *c_1 && !p; ++c_1)
        for (const char *c_2 = sym; *c_2 && !p; ++c_2)
            if (*c_1 == *c_2)
                p = c_1;
    return p;
}

size_t my_strspn(const char *str, const char *sym)
{
    size_t len = 0;
    int found = 1;
    for (const char *c_1 = str; *c_1 && found; ++c_1)
    {
        found = 0;
        for (const char *c_2 = sym; *c_2; ++c_2)
            if (*c_1 == *c_2)
                found = 1;
        if (found)
            len++;
    }
    return len;
}

size_t my_strcspn(const char *str, const char *sym)
{
    size_t len = 0;
    int found = 0;
    for (const char *c_1 = str; *c_1 && !found; ++c_1)
    {
        for (const char *c_2 = sym; *c_2; ++c_2)
            if (*c_1 == *c_2)
                found = 1;
        if (!found)
            len++;
    }
    return len;
}

const char *my_strchr(const char *str, int ch)
{
    const char *p = NULL;
    const char *c_1;
    for (c_1 = str; *c_1 && !p; ++c_1)
        if (*c_1 == ch)
            p = c_1;
    if (ch == 0)
        p = c_1;
    return p;
}

const char *my_strrchr(const char *str, int ch)
{
    const char *p = NULL;
    const char *c_1;
    for (c_1 = str; *c_1; ++c_1)
        if (*c_1 == ch)
            p = c_1;
    if (ch == 0)
        p = c_1;
    return p;
}
