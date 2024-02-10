#pragma once
#include <time.h>
#include <windows.h>
#include "sum.h"

//������ ��� ���������� ����������� ������

//������� ��� ������������ ������� ������
void Swap(int*** Arr3D, int M, int N, int imin, int s);

//������� ��� ������ ���� ������ ��������� �������� ����������
clock_t timeQuickSort(int L, int R, int*** Arr3D, int P, int M, int N);

//�������� �������� ����������
void quickSort(int* Sum, int L, int R, int*** Arr3D, int P, int M, int N);

//�������� ������ ����� 5
clock_t Select5(int*** Arr3D, int P, int M, int N);

//�������� ������ ����� 8
clock_t Select8(int*** Arr3D, int P, int M, int N);
