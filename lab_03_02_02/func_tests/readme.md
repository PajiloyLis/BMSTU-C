# Тесты для лабораторной работы №03

## Входные данные
n, m - число строк и столбцов матрицы соответственно
a11, a12, ... anm - целые числа, элементы матрицы

## Выходные данные
Строки исходной матрицы, отсортированные по возрастанию произведений их элементов

## Позитивные тесты:
- 01 - обычный тест
- 02 - входная матрица минимальной размерности
- 03 - в ответ не добавляются строки
- 04 - к каждой строке добавляется новая
- 05 - обычный тест
- 06 - тест максимального размера, с максимальным числом добавлений

## Негативные тесты:
- 01 - буква вместо первой размерности
- 02 - буква вместо второй размерности
- 03 - буква вместо одного из элементов
- 04 - нулевая первая размерность
- 05 - нулевая вторая размерность
- 06 - первая размерность больше 10
- 07 - вторая размерность больше 10