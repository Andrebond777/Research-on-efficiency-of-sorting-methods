#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>

//������ ��� ���������� ������������ ������

//������� ��� ������ ���� ������ ��������� �������� ����������
clock_t Vtime_quick_sort(int n, int* A, int l, int r);

//�������� �������� ����������
void Vquick_sort(int n, int* A, int l, int r);

//�������� ������ ����� 5
clock_t VSelect5(int* A, int N);

//�������� ������ ����� 8
clock_t VSelect8(int* A, int N);