#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define STRLEN 4
#define COMMANDS_VARIANTS_CNT 4

#define COMMAND_INPUT_ERROR 10
#define NUMBERS_COUNT_INPUT_ERROR 11
#define ARGUMENT_VALUE_INPUT_ERROR 12

enum comands_t
{
    CALC_VALUE,
    CALC_DERIVATIVE,
    CALC_SUM,
    SPLIT_POWS
};

typedef enum comands_t comands_t;

int command_input(comands_t *command);

int input_numbers_cnt(size_t *n);

void calc_x_pows(long long *array, size_t n, int x);

int main(void)
{
    int rc = EXIT_SUCCESS;
    comands_t command;
    size_t n = 0, n_1 = 0;
    int x;
    long long ans = 0;
    node_t *list = NULL, *buf_1 = NULL, *buf_2 = NULL;
    rc = command_input(&command);
    rc = rc == EXIT_SUCCESS ? input_numbers_cnt(&n) : rc;
    long long x_pows[n];
    if (rc == EXIT_SUCCESS)
        list = list_allocate(n);
    if (!list)
        rc = LIST_ALLOCATION_ERROR;
    rc = rc == EXIT_SUCCESS ? list_values_input(list) : rc;
    if (rc == EXIT_SUCCESS)
    {
        switch (command)
        {
            case CALC_VALUE:
                if (scanf("%d", &x) != 1)
                    rc = ARGUMENT_VALUE_INPUT_ERROR;
                else
                {
                    calc_x_pows(x_pows, n, x);
                    rc = calc_value_by_x(list, x_pows, n, &ans);
                    if (rc == EXIT_SUCCESS)
                        printf("%lld", ans);
                }
                break;
            case CALC_DERIVATIVE:
                buf_1 = list_allocate(n - 1);
                if (!buf_1 && n > 1)
                    rc = LIST_ALLOCATION_ERROR;
                rc = calc_derivative(list, buf_1, n);
                if (rc == EXIT_SUCCESS)
                {
                    print_list(buf_1);
                    printf("L\n");
                }
                break;
            case CALC_SUM:
                rc = input_numbers_cnt(&n_1);
                if (rc == EXIT_SUCCESS)
                    buf_1 = list_allocate(n_1);
                if (!buf_1)
                    rc = LIST_ALLOCATION_ERROR;
                rc = rc == EXIT_SUCCESS ? list_values_input(buf_1) : rc;
                if (rc == EXIT_SUCCESS)
                    buf_2 = list_allocate(n_1 > n ? n_1 : n);
                if (!buf_2)
                    rc = LIST_ALLOCATION_ERROR;
                rc = rc == EXIT_SUCCESS ? calc_coef_sum(list, n, buf_1, n_1, buf_2) : rc;
                if (rc == EXIT_SUCCESS)
                {
                    print_list(buf_2);
                    printf("L\n");
                }
                break;
            case SPLIT_POWS:
                buf_1 = list_allocate(n / 2 + n % 2);
                if (!buf_1 && n / 2 > 0)
                    rc = LIST_ALLOCATION_ERROR;
                if (rc == EXIT_SUCCESS)
                    buf_2 = list_allocate(n / 2);
                if (!buf_2 && n / 2 > 0)
                    rc = LIST_ALLOCATION_ERROR;
                rc = rc == EXIT_SUCCESS ? split_coefs_by_parity(list, n, buf_1, buf_2) : rc;
                if (rc == EXIT_SUCCESS)
                {
                    if (buf_1)
                    {
                        print_list(buf_1);
                        printf("L\n");
                    }
                    if (buf_2)
                    {
                        print_list(buf_2);
                        printf("L\n");
                    }
                }
                break;
        }
    }
    if (list)
        list_free(list);
    if (buf_1)
        list_free(buf_1);
    if (buf_2)
        list_free(buf_2);
    return rc;
}

void calc_x_pows(long long *array, size_t n, int x)
{
    array[0] = 1;
    for (size_t i = 1; i < n; ++i)
    {
        array[i] = x;
        if (i)
            array[i] *= array[i - 1];
    }
}

int input_numbers_cnt(size_t *n)
{
    int buf;
    *n = 0;
    if (scanf("%d", &buf) != 1)
        return NUMBERS_COUNT_INPUT_ERROR;
    if (buf <= 0)
        return NUMBERS_COUNT_INPUT_ERROR;
    *n = buf;
    return EXIT_SUCCESS;
}

int command_input(comands_t *command)
{
    char str[STRLEN];
    char *comand_variants[] = { "val", "ddx", "sum", "dvd" };
    if (scanf("%s", str) != 1)
        return COMMAND_INPUT_ERROR;
    int found = 0;
    for (int i = 0; i < COMMANDS_VARIANTS_CNT && !found; ++i)
        if (!strcmp(str, comand_variants[i]))
        {
            found = 1;
            *command = i;
        }
    if (!found)
        return COMMAND_INPUT_ERROR;
    return EXIT_SUCCESS;
}