#pragma once
#include <time.h>
#include <windows.h>
#include "sum.h"

//модуль для сортування тривимірного масиву

//функція для перестановки перерізів місцями
void Swap(int*** Arr3D, int M, int N, int imin, int s);

//функція для пошуку часу роботи алгоритму швидкого сортування
clock_t timeQuickSort(int L, int R, int*** Arr3D, int P, int M, int N);

//алгоритм швидкого сортування
void quickSort(int* Sum, int L, int R, int*** Arr3D, int P, int M, int N);

//алгоритм вибору номер 5
clock_t Select5(int*** Arr3D, int P, int M, int N);

//алгоритм вибору номер 8
clock_t Select8(int*** Arr3D, int P, int M, int N);
