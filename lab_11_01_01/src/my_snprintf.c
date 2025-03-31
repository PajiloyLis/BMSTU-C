#include "my_snprintf.h"

static size_t my_strlen(const char *s);

static size_t calc_num_size(void);

static void str_reverse(char *str, size_t n);

static void my_itoa(unsigned long n, char *str, int base);

#define DEC_BASE 10
#define OCT_BASE 8
#define HEX_BASE 16

int my_snprintf(char *restrict s, size_t n, const char *restrict format, ...)
{
    if (!format)
    {
        return -1;
    }
    va_list param;
    va_start(param, format);
    long value;
    unsigned long abs_value;
    int correct = 0;
    size_t bytes_written = 0;
    char str_num[calc_num_size()];
    for (size_t i = 0; i < my_strlen(format);)
    {
        if (format[i] == '%')
        {
            ++i;
            if (format[i] == 'c')
            {
                if (n && bytes_written < n - 1)
                    s[bytes_written] = (char)va_arg(param, int);
                ++i, bytes_written++;
            }
            else if (format[i] == 's')
            {
                for (char *cur = va_arg(param, char *); *cur; ++cur, ++bytes_written)
                    if (n && bytes_written < n - 1)
                        s[bytes_written] = *cur;
                i++;
            }
            else
            {
                int negative = 0;
                if (format[i] == 'd' || format[i] == 'i')
                {
                    value = va_arg(param, int);
                    if (value < 0)
                    {
                        negative = 1;
                        value *= -1;
                    }
                    my_itoa(value, str_num, DEC_BASE);
                    i++;
                    correct = 1;
                }
                else if (format[i] == 'o' || format[i] == 'x')
                {
                    abs_value = va_arg(param, unsigned);
                    if (format[i] == 'o')
                        my_itoa(abs_value, str_num, OCT_BASE);
                    else
                        my_itoa(abs_value, str_num, HEX_BASE);
                    i++;
                    correct = 1;
                }
                else if (format[i] == 'h' || format[i] == 'l')
                {
                    i++;
                    if (format[i] == 'd' || format[i] == 'i')
                    {
                        if (format[i - 1] == 'h')
                            value = (short)va_arg(param, int);
                        else
                            value = va_arg(param, long);
                        if (value < 0)
                        {
                            negative = 1;
                            value *= -1;
                        }
                        my_itoa(value, str_num, DEC_BASE);
                        i++;
                        correct = 1;
                    }
                    else if (format[i] == 'o' || format[i] == 'x')
                    {
                        if (format[i - 1] == 'h')
                            abs_value = (unsigned short)va_arg(param, int);
                        else
                            abs_value = va_arg(param, unsigned long);
                        if (format[i] == 'o')
                            my_itoa(abs_value, str_num, OCT_BASE);
                        else
                            my_itoa(abs_value, str_num, HEX_BASE);
                        i++;
                        correct = 1;
                    }
                    else
                    {
                        correct = 0;
                        i++;
                    }
                }
                else
                {
                    correct = 0;
                    i++;
                }
                if (correct)
                {
                    if (negative)
                    {
                        s[bytes_written] = '-';
                        bytes_written++;
                    }
                    for (char *cur = str_num; *cur; ++cur, ++bytes_written)
                        if (n && bytes_written < n - 1)
                            s[bytes_written] = *cur;
                    correct = negative = 0;
                }
            }
        }
        else
        {
            if (n && bytes_written < n - 1)
                s[bytes_written] = format[i];
            ++i, ++bytes_written;
        }
    }
    if (n)
        s[(bytes_written < n - 1 ? bytes_written : n - 1)] = 0;
    va_end(param);
    return bytes_written;
}

static size_t my_strlen(const char *s)
{
    const char *cur;
    for (cur = s; *cur; cur++);
    return cur - s;
}

static size_t calc_num_size(void)
{
    size_t n = 0;
    long buf = ULONG_MAX;
    while (buf)
    {
        buf /= OCT_BASE;
        n++;
    }
    n = (size_t)(1.5 * n);
    return n;
}

static void my_itoa(unsigned long n, char *str, int base)
{
    int i = 0, digit;
    if (n == 0)
        str[i++] = '0';
    else
    {
        while (n)
        {
            digit = n % base;
            if (digit > DEC_BASE - 1)
                str[i++] = digit - DEC_BASE + 'a';
            else
                str[i++] = n % base + '0';
            n /= base;
        }
    }
    str[i] = 0;
    str_reverse(str, i);
}

static void str_reverse(char *str, size_t n)
{
    for (size_t j = 0, i = n - 1; j < i; ++j, --i)
    {
        if (str[i] != str[j])
        {
            str[i] = str[i] ^ str[j];
            str[j] = str[i] ^ str[j];
            str[i] = str[j] ^ str[i];
        }
    }
}