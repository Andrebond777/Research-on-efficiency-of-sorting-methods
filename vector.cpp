#include"vector.h"

clock_t Vtime_quick_sort(int n, int* A, int L, int R)
{
	clock_t time_start, time_stop;

	time_start = clock();
	Vquick_sort(n, A, L, R);
	time_stop = clock();

	return time_stop - time_start;
}

void Vquick_sort(int n, int* A, int L, int R)
{
	int b, i, j;
	b = A[(L + R) / 2];
	i = L; j = R;
	while (i <= j)
	{
		while (A[i] < b)i++;
		while (A[j] > b)j--;
		if (i <= j)
		{
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	}
	if (L < j)
		Vquick_sort(n, A, L, j);
	if (i < R)
		Vquick_sort(n, A, i, R);
}



clock_t VSelect5(int* A, int N)
{
	int Min, imin;
	clock_t time_start, time_stop;
	time_start = clock();
	for (int s = 0; s < N - 1; s++)
	{
		Min = A[s];
		imin = s;
		for (int i = s + 1; i < N; i++)
			if (A[i] < Min)
			{
				Min = A[i];
				imin = i;
			}
		if (imin != s)
		{
			A[imin] = A[s];
			A[s] = Min;
		}
	}
	time_stop = clock();
	return time_stop - time_start;
}


clock_t VSelect8(int* A, int N)
{
	int L, R, imin, imax, tmp;
	clock_t time_start, time_stop;
	time_start = clock();

	L = 0; R = N - 1;
	while (L < R)
	{
		imin = L;
		imax = L;
		for (int i = L + 1; i < R + 1; i++)
			if (A[i] < A[imin])
				imin = i;
			else if (A[i] > A[imax])
				imax = i;
		if (imin != L)
		{
			tmp = A[imin];
			A[imin] = A[L];
			A[L] = tmp;
		}

		if (imax != R)
			if (imax == L)
			{
				tmp = A[imin];
				A[imin] = A[R];
				A[R] = tmp;
			}
			else
			{
				tmp = A[imax];
				A[imax] = A[R];
				A[R] = tmp;
			}

		L = L + 1;
		R = R - 1;
	}

	time_stop = clock();
	return time_stop - time_start;
}