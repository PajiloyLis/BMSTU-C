# Тесты для лабораторной работы №03

## Входные данные
n, n - число строк и столбцов квадртной матрицы соответственно
a11, a12, ... ann - целые числа, элементы матрицы

## Выходные данные
c - наибольшее число под главной диагональю, последняя цифра которого равна 5 (наибольшее "хорошее" число)

## Позитивные тесты:
- 01 - одно "хорошее" число под главной диагональню, все числа положительные
- 02 - несколько "хороших" чисел под главной диагональю, все числа положительные
- 03 - одно "хорошее" число под главной диагональю, присутствуют отрицательные числа
- 04 - несколько "хороших" чисел под главной диагональю, присутствуют отрицательные числа
- 05 - общий тест максимального размера

## Негативные тесты:
- 01 - буква вместо первой размерности
- 02 - буква вместо второй размерности
- 03 - буква вместо одного из элементов
- 04 - нулевая первая размерность
- 05 - нулевая вторая размерность
- 06 - первая размерность больше 10
- 07 - вторая размерность больше 10
- 08 - отсутствуют "хорошие числа" под главной диагональю
- 09 - тест размера 1x1