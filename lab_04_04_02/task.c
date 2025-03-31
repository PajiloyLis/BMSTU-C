#include "task.h"

void parse(char *str, char *parsed[], size_t *n);

int check_if_year(char *str);

int check_if_month(char *str, char months[][WORD_SIZE], int *month_num);

void str_to_lower(char *str);

int check_if_day(char *day, int month, int year);

int check_if_leap_year(int year);

int check_day_in_month(int month, int day, int year);

int to_int(char *str);

void parse(char *str, char *parsed[], size_t *n)
{
    int return_code = EXIT_SUCCESS;
    *n = 0;
    char *delimeters = "\n\r\t ";
    parsed[*n] = strtok(str, delimeters);
    while (parsed[*n] != NULL && return_code == EXIT_SUCCESS)
    {
        (*n)++;
        parsed[*n] = strtok(NULL, delimeters);
    }
}

int solve(char *str)
{
    int return_code = TRUE;
    if (!strlen(str))
    {
        return_code = FALSE;
    }
    else
    {
        char *parsed[SIZE];
        size_t parsed_n = 0;
        parse(str, parsed, &parsed_n);
        int month_num = 0;
        if (parsed_n != 3)
        {
            return_code = FALSE;
        }
        else
        {
            char months[][WORD_SIZE] = { "january",
                "february",
                "march",
                "april",
                "may",
                "june",
                "july",
                "august",
                "september",
                "october",
                "november",
                "december" };
            if (check_if_year(parsed[2]))
            {
                str_to_lower(parsed[1]);
                if (check_if_month(parsed[1], months, &month_num))
                {
                    int year = to_int(parsed[2]);
                    if (!check_if_day(parsed[0], month_num, year))
                    {
                        return_code = FALSE;
                    }
                }
                else
                {
                    return_code = FALSE;
                }
            }
            else
            {
                return_code = FALSE;
            }
        }
    }
    return return_code;
}

int check_if_year(char *str)
{
    int return_code = TRUE;
    size_t i;
    for (i = 0; str[i] && return_code; ++i)
        if (str[i] < '0' || str[i] > '9')
            return_code = FALSE;
    if (return_code && to_int(str) == 0)
        return_code = FALSE;
    return return_code;
}

void str_to_lower(char *str)
{
    for (size_t i = 0; str[i]; ++i)
    {
        str[i] = tolower(str[i]);
    }
}

int check_if_month(char *str, char months[][WORD_SIZE], int *month_num)
{
    int return_code = FALSE;
    for (size_t i = 0; i < MONTHS && !return_code; ++i)
    {
        if (!strcmp(str, months[i]))
        {
            *month_num = i + 1;
            return_code = TRUE;
        }
    }
    return return_code;
}

int check_if_day(char *day, int month, int year)
{
    int return_code = TRUE;
    size_t i;
    for (i = 0; day[i] && return_code; ++i)
        if (day[i] < '0' || day[i] > '9')
            return_code = FALSE;
    if (return_code)
    {
        int date = to_int(day);
        if (!check_day_in_month(month, date, year))
        {
            return_code = FALSE;
        }
    }
    return return_code;
}

int check_day_in_month(int month, int day, int year)
{
    return day > 0 && day <= (28 + (month + month / 8) % 2 + 2 % month + 2 * 1 / month - (!check_if_leap_year(year) && month == 2));
}

int check_if_leap_year(int year)
{
    int return_code = FALSE;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return_code = TRUE;
    }
    return return_code;
}

int to_int(char *str)
{
    int result = 0;
    for (size_t i = 0; str[i]; ++i)
        result = result * 10 + (str[i] - '0');
    return result;
}
