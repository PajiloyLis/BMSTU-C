#include "strlib.h"

int parse(char *str, char *parsed[], size_t *n);

void find_all(char *strings_1[], size_t n_1, char *strings_2[], size_t n_2, char ans[][WORD_SIZE * 2], size_t *ans_n);

int check_repeat(char *strings[], size_t n);

int find(char *strings[], size_t n, char *string);

int solution(char *str_1, char *str_2, char ans[][WORD_SIZE * 2], size_t *ans_n)
{
    int return_code = EXIT_SUCCESS;
    char *parsed_1[SIZE + 1], *parsed_2[SIZE + 1];
    size_t n_1 = 0, n_2 = 0;
    if (parse(str_1, parsed_1, &n_1) == EXIT_SUCCESS && parse(str_2, parsed_2, &n_2) == EXIT_SUCCESS)
    {
        find_all(parsed_1, n_1, parsed_2, n_2, ans, ans_n);
    }
    else
    {
        return_code = EXIT_FAILURE;
    }
    return return_code;
}

int parse(char *str, char *parsed[], size_t *n)
{
    int return_code = EXIT_SUCCESS;
    *n = 0;
    char *spaces = ",.;:-!?";
    char *p_word = str;
    char *c;
    for (c = str; *c && return_code == EXIT_SUCCESS; ++c)
    {
        if ((strchr(spaces, *c) || isspace(*c)) && !strchr(spaces, *p_word) && !isspace(*p_word))
        {
            if (c - p_word > WORD_SIZE)
            {
                return_code = EXIT_FAILURE;
            }
            else
            {
                *(parsed + (*n)) = p_word;
                *c = '\0';
                p_word = c + 1;
                (*n)++;
            }
        }
        else if (!strchr(spaces, *c) && !isspace(*c) && (strchr(spaces, *p_word) || isspace(*p_word)))
        {
            p_word = c;
        }
    }
    if (!strchr(spaces, *p_word) && !isspace(*p_word) && return_code == EXIT_SUCCESS)
    {
        if (c - p_word > WORD_SIZE)
        {
            return_code = EXIT_FAILURE;
        }
        else
        {
            *(parsed + (*n)) = p_word;
            (*n)++;
        }
    }
    if (*n == 0)
        return_code = EXIT_FAILURE;
    return return_code;
}

void find_all(char *strings_1[], size_t n_1, char *strings_2[], size_t n_2, char ans[][WORD_SIZE * 2], size_t *ans_n)
{
    *ans_n = 0;
    for (size_t i = 0; i < n_1; ++i)
    {
        if (!check_repeat(strings_1, i))
        {
            strcpy(ans[*ans_n], *(strings_1 + i));
            if (find(strings_2, n_2, *(strings_1 + i)))
            {
                strcat(ans[*ans_n], " yes");
            }
            else
            {
                strcat(ans[*ans_n], " no");
            }
            ++(*ans_n);
        }
    }
}

int check_repeat(char *strings[], size_t n)
{
    int repeated = 0;
    for (size_t i = 0; i < n && !repeated; ++i)
    {
        if (!strcmp(*(strings + i), *(strings + n)))
        {
            repeated = 1;
        }
    }
    return repeated;
}

int find(char *strings[], size_t n, char *string)
{
    int finded = 0;
    for (size_t i = 0; i < n && !finded; ++i)
    {
        if (!strcmp(*(strings + i), string))
        {
            finded = 1;
        }
    }
    return finded;
}
