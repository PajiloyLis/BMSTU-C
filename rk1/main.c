#include <stdio.h>
#include<stdlib.h>

#define EMPTY 0
#define ONE_P 1
#define TWO_P 2
#define THREE_P 3
#define FOUR_P 4

#define SIZE 10

typedef int matrix[SIZE][SIZE];

int input(matrix matr, size_t *n)
{
    int return_code = EXIT_SUCCESS;
    printf("Input row and column number: ");
    if(scanf("%zu", n) != 1 || *n > SIZE || *n < 0){
        return_code = EXIT_FAILURE;
    }
    else
    {
        for(size_t i = 0; i < *n && !return_code; ++i)
        {
            for(size_t j = 0; j < *n && !return_code; ++j)
            {
                if(scanf("%d", *(matr+i)+j) != 1 || matr[i][j] < EMPTY || matr[i][j] > FOUR_P)
                {
                    return_code = EXIT_FAILURE;
                }
            }
        }
    }
    return return_code;
}

//int check_correct(matrix matr, size_t n)
//{
//    int cnt = 0;
//    for(size_t i = 0; i < n; ++i)
//    {
//        for(size_t j = 0; j < n; ++j)
//        {
//            if(matr[i][j] != EMPTY){
//                printf("%zu %zu ", i, j);
//                int new_mistake = 0;
//                int fault = 0
//                for (int delta_x = -1; delta_x < 2 && !fault; ++delta_x)
//                {
//                    for (int delta_y = -1; delta_y < 2 !fault; ++delta_y)
//                    {
//                        if((int)i + delta_y >= 0 &&(int)i + delta_y < n && (int)j + delta_x >= 0 && (int)j + delta_x < n && matr[i + delta_y][j + delta_x] !=EMPTY)
//                        {
//                            printf("%d %d ", delta_x, delta_y);
//                            if(matr[i][j] == ONE_P)
//                                fault ++;
//                            else if(matr[i][j] == TWO_P && (matr[i + delta_y][j + delta_x] != matr[i][j] && new_mistake == 1))
//                            {
//                                new_mistake++
//                            }
//                        }
//                    }
//                }
//                cnt += new_mistake;
//                printf("%d\n", cnt);
//            }
//        }
//    }
//    return cnt;
//}

void output(matrix matr, size_t n){
    printf("\nColum and row number is %zu\n", n);
    for(size_t i = 0; i < n; ++i)
    {
        for(size_t j = 0; j < n; ++j)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int exit_code = EXIT_SUCCESS;
    matrix matr;
    size_t n;
    if(input(matr, &n) == EXIT_FAILURE)
    {
        printf("Input error\n");
        exit_code = EXIT_FAILURE;
    }
    else
    {
        //int mistakes_count = check_correct(matr, n);
        output(matr, n);
    }
    return exit_code;
}
