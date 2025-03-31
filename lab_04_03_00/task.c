#include "task.h"

int parse(char *str, char *parsed[], size_t *n);

int make_ans(char *ans, char *parsed[], size_t n);

void remove_letters(char *str);

int solution(char *string, char *ans)
{
    int return_code = EXIT_SUCCESS;
    char *parsed[SIZE];
    size_t parsed_n = 0;
    if (parse(string, parsed, &parsed_n) == EXIT_FAILURE)
        return_code = EXIT_FAILURE;
    else
    {
        return_code = make_ans(ans, parsed, parsed_n);
    }
    return return_code;
}

int parse(char *str, char *parsed[], size_t *n)
{
    int return_code = EXIT_SUCCESS;
    *n = 0;
    char *delimeters = "\n\r\t ,;:-.!?";
    parsed[*n] = strtok(str, delimeters);
    if (parsed[*n] && strlen(parsed[*n]) > WORD_SIZE)
    {
        return_code = EXIT_FAILURE;
    }
    while (parsed[*n] != NULL && return_code == EXIT_SUCCESS)
    {
        (*n)++;
        parsed[*n] = strtok(NULL, delimeters);
        if (parsed[*n] && strlen(parsed[*n]) > WORD_SIZE)
        {
            return_code = EXIT_FAILURE;
        }
    }
    if (*n == 0)
    {
        return_code = EXIT_FAILURE;
    }
    return return_code;
}

int make_ans(char *ans, char *parsed[], size_t n)
{
    int return_code = EXIT_SUCCESS;
    for (int i = n - 1; i >= 0; --i)
    {
        if (strcmp(parsed[i], parsed[n - 1]))
        {
            remove_letters(parsed[i]);
            strcat(ans, parsed[i]);
            if (i)
            {
                strcat(ans, " ");
            }
        }
    }
    if (strlen(ans) == 0)
    {
        return_code = EXIT_FAILURE;
    }
    return return_code;
}

void remove_letters(char *str)
{
    size_t shift = 0, i;
    for (i = 1; str[i]; ++i)
    {
        if (str[i] == str[0])
            shift++;
        else
            str[i - shift] = str[i];
    }
    str[i - shift] = '\0';
}
