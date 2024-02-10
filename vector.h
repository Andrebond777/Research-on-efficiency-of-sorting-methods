#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>

//модуль для сортування одновимірного масиву

//функція для пошуку часу роботи алгоритму швидкого сортування
clock_t Vtime_quick_sort(int n, int* A, int l, int r);

//алгоритм швидкого сортування
void Vquick_sort(int n, int* A, int l, int r);

//алгоритм вибору номер 5
clock_t VSelect5(int* A, int N);

//алгоритм вибору номер 8
clock_t VSelect8(int* A, int N);