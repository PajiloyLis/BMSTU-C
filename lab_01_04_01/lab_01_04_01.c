#include <stdio.h>
#define FLATS 4
#define FLOORS 9

int get_entrance_num(int);

int get_floor_num(int);

int main(void)
{
    int number;
    int entrance_num, floor_num;
    scanf("%d", &number);
    entrance_num = get_entrance_num(number);
    floor_num = get_floor_num(number);
    printf("Entrace number is: %d\nFloor number is: %d\n", entrance_num, floor_num);
    return 0;
}

int get_entrance_num(int number)
{
    return (number - 1) / (FLATS * FLOORS) + 1;
}

int get_floor_num(int number)
{
    return (number - 1) % (FLATS * FLOORS) / FLATS + 1;
}
