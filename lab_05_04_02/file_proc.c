#include "file_proc.h"

int get_record_cnt(FILE *f, size_t *n);

bool cmp(good *a, good *b);

bool is_suf(char *str, char *substr);

int swap(good *pval, size_t p_i, good *val, size_t i, FILE *f);

int sort_file(FILE *f_out, good *val, good *val_2);

int find(FILE *f, char *sub, good *val);

int append(FILE *f, good *val, good *pval);

int copy(FILE *f_in, FILE *f_out, good *val);

int file_check(FILE *f);

int start_sort(char *file_in, char *file_out, good *val, good *val_2);

int start_find(char *file, char *suf, good *val);

int start_append(char *file, good *val, good *val_2);

int solution(char *mode, char *third_param, char *file_name, good *val, good *val_2)
{
    int return_code = EXIT_SUCCESS;
    if (!strcmp(mode, "sb"))
    {
        return_code = start_sort(file_name, third_param, val, val_2);
    }
    else if (!strcmp(mode, "fb"))
    {
        return_code = start_find(file_name, third_param, val);
    }
    else if (!strcmp(mode, "ab"))
    {
        return_code = start_append(file_name, val, val_2);
    }
    else
    {
        return_code = ERROR_IN_ARGS;
    }
    return return_code;
}

int start_sort(char *file_in, char *file_out, good *val, good *val_2)
{
    int return_code = EXIT_SUCCESS;
    FILE *f_out = fopen(file_out, "wb"), *f_in = fopen(file_in, "rb");
    if (!f_out || !f_in)
    {
        return_code = FILE_OPEN_ERROR;
        if (f_out)
        {
            fclose(f_out);
        }
        if (f_in)
        {
            fclose(f_in);
        }
    }
    else if (get_from_pos(val, 0, f_in) != EXIT_SUCCESS || file_check(f_in) != EXIT_SUCCESS)
    {
        fclose(f_in);
        fclose(f_out);
        return_code = FILE_EMPTY_ERROR;
    }
    else
    {
        return_code = copy(f_in, f_out, val);
        fclose(f_out);
        fclose(f_in);
        if (return_code == EXIT_SUCCESS)
        {
            f_out = fopen(file_out, "r+b");
            if (!f_out)
            {
                return_code = FILE_OPEN_ERROR;
            }
            else
            {
                return_code = sort_file(f_out, val, val_2);
                fclose(f_out);
            }
        }
    }
    return return_code;
}

int start_find(char *file, char *suf, good *val)
{
    int return_code = EXIT_SUCCESS;
    FILE *f_in = fopen(file, "rb");
    if (!f_in)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else if (get_from_pos(val, 0, f_in) != EXIT_SUCCESS || file_check(f_in) != EXIT_SUCCESS)
    {
        fclose(f_in);
        return_code = FILE_EMPTY_ERROR;
    }
    else
    {
        return_code = find(f_in, suf, val);
        fclose(f_in);
    }
    return return_code;
}

int start_append(char *file, good *val, good *val_2)
{
    int return_code = EXIT_SUCCESS;
    FILE *f_in = fopen(file, "r+b");
    if (!f_in)
    {
        return_code = FILE_OPEN_ERROR;
    }
    else if (get_from_pos(val, 0, f_in) != EXIT_SUCCESS || file_check(f_in) != EXIT_SUCCESS)
    {
        fclose(f_in);
        return_code = FILE_EMPTY_ERROR;
    }
    else
    {
        return_code = append(f_in, val, val_2);
        fclose(f_in);
    }
    return return_code;
}

int sort_file(FILE *f_out, good *cur, good *prev)
{
    int return_code = EXIT_SUCCESS;
    size_t n = 0;
    return_code = get_record_cnt(f_out, &n);
    bool swapped;
    for (size_t i = 1; i < n && return_code == EXIT_SUCCESS; ++i)
    {
        swapped = true;
        return_code = get_from_pos(cur, i, f_out);
        for (int j = i - 1; j >= 0 && swapped && return_code == EXIT_SUCCESS; --j)
        {
            swapped = false;
            return_code = get_from_pos(prev, j, f_out);
            if (return_code == EXIT_SUCCESS && cmp(cur, prev))
            {
                swapped = true;
                return_code = swap(prev, j, cur, j + 1, f_out);
            }
        }
    }
    return return_code;
}

int find(FILE *f, char *sub, good *val)
{
    int return_code = EXIT_SUCCESS;
    size_t n = 0;
    int counter = 0;
    return_code = get_record_cnt(f, &n);
    if (return_code == EXIT_SUCCESS)
    {
        for (size_t i = 0; i < n && return_code == EXIT_SUCCESS; ++i)
        {
            return_code = get_from_pos(val, i, f);
            if (return_code == EXIT_SUCCESS && is_suf(val->name, sub))
            {
                counter++;
                output(val);
            }
        }
    }
    if (!counter)
    {
        return_code = PATTERN_ERROR;
    }
    return return_code;
}

int append(FILE *f, good *val, good *pval)
{
    int return_code = EXIT_SUCCESS;
    size_t n = 0;
    return_code = get_record_cnt(f, &n);
    if (return_code == EXIT_SUCCESS)
    {
        return_code = input(val);
    }
    if (return_code == EXIT_SUCCESS)
    {
        return_code = fseek(f, 0, SEEK_END);
    }
    if (return_code == EXIT_SUCCESS)
    {
        fwrite(val, sizeof(good), 1, f);
        bool swapped = true;
        for (int i = n - 1; i >= 0 && swapped && return_code == EXIT_SUCCESS; --i)
        {
            swapped = false;
            return_code = get_from_pos(pval, i, f);
            if (return_code == EXIT_SUCCESS && cmp(val, pval))
            {
                swapped = true;
                return_code = swap(pval, i, val, i + 1, f);
            }
        }
    }
    return return_code;
}

int copy(FILE *f_in, FILE *f_out, good *val)
{
    int return_code = EXIT_SUCCESS;
    size_t n;
    return_code = get_record_cnt(f_in, &n);
    for (size_t i = 0; i < n && return_code == EXIT_SUCCESS; ++i)
    {
        return_code = get_from_pos(val, i, f_in);
        return_code = (return_code == EXIT_SUCCESS ? set_by_pos(val, i, f_out) : return_code);
    }
    return return_code;
}

int swap(good *pval, size_t p_i, good *val, size_t i, FILE *f)
{
    int return_code = EXIT_SUCCESS;
    return_code = set_by_pos(val, p_i, f);
    return_code = ((return_code == EXIT_SUCCESS) ? set_by_pos(pval, i, f) : return_code);
    return return_code;
}

bool is_suf(char *str, char *substr)
{
    bool bool_equal = false;
    size_t str_l = strlen(str), sub_l = strlen(substr);
    if (sub_l > str_l)
    {
        bool_equal = false;
    }
    else if (!strcmp(str + str_l - sub_l, substr))
    {
        bool_equal = true;
    }
    return bool_equal;
}

int get_record_cnt(FILE *f, size_t *n)
{
    int return_code = EXIT_SUCCESS;
    return_code = fseek(f, 0, SEEK_END);
    if (return_code == EXIT_SUCCESS)
    {
        if (ftell(f) % sizeof(good) != 0)
        {
            return_code = FILE_GET_CNT_ERROR;
        }
        else
        {
            *n = ftell(f) / sizeof(good);
        }
    }
    else
    {
        return_code = FILE_GET_CNT_ERROR;
    }
    return return_code;
}

int file_check(FILE *f)
{
    int return_code = EXIT_SUCCESS;
    return_code = fseek(f, 0, SEEK_END);
    if (return_code == EXIT_SUCCESS)
    {
        return_code = (ftell(f) % sizeof(good) == 0 ? EXIT_SUCCESS : FILE_GET_CNT_ERROR);
    }
    return return_code;
}

bool cmp(good *a, good *b)
{
    bool bool_more = false;
    if (a->cost > b->cost || (a->cost == b->cost && a->count > b->count))
    {
        bool_more = true;
    }
    return bool_more;
}
