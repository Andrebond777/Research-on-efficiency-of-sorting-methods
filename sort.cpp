#include "sort.h"


void Swap(int*** Arr3D, int M, int N, int imin, int s)
{

	int tmp;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp = Arr3D[imin][i][j];
			Arr3D[imin][i][j] = Arr3D[s][i][j];
			Arr3D[s][i][j] = tmp;
		}
	}

}

clock_t timeQuickSort(int L, int R, int*** Arr3D, int P, int M, int N)
{
	clock_t time_start, time_stop;
	
	time_start = clock();
	int* Sum = new int[P];
	sum(Arr3D, Sum, P, M, N);
	quickSort(Sum, 0, P - 1, Arr3D, P, M, N);
	time_stop = clock();
	
	delete[]Sum;
	return time_stop - time_start;
}

void quickSort(int* Sum, int L, int R, int*** Arr3D, int P, int M, int N)
{
	int B, tmp, i, j; 

	B = Sum[(L + R) / 2];		// центральний елемент
	i = L, j = R;
	// процедура розділення
	while (i <= j)
	{
		while (Sum[i] < B) i++;
		while (Sum[j] > B) j--;

		if (i <= j) {
			tmp = Sum[i];
			Sum[i] = Sum[j];
			Sum[j] = tmp;
			Swap(Arr3D, M, N, i, j);
			i++;
			j--;
		}
	}

	// рекурсивні виклики, якщо є, що сортувати
	if (L < j) quickSort(Sum, L, j, Arr3D, P, M, N);
	if (i < R) quickSort(Sum, i, R, Arr3D, P, M, N);
}

clock_t Select5(int*** Arr3D, int P, int M, int N)
{
	int Min, imin;
	clock_t time_start, time_stop;
	time_start = clock();

	int* Sum = new int[P];
	sum(Arr3D, Sum, P, M, N);

	for (int s = 0; s < P - 1; s++)
	{
		Min = Sum[s];
		imin = s;
		for (int i = s + 1; i < P; i++)
			if (Sum[i] < Min)
			{
				Min = Sum[i];
				imin = i;
			}
		if (imin != s)
		{
			Sum[imin] = Sum[s];
			Sum[s] = Min;
			Swap(Arr3D, M, N, imin, s);
		}
	}

	delete[]Sum;

	time_stop = clock();
	return time_stop - time_start;
}

clock_t Select8(int*** Arr3D, int P, int M, int N)
{
	int L, R, imin, imax, tmp;
	clock_t time_start, time_stop;
	time_start = clock();

	int* Sum = new int[P];
	sum(Arr3D, Sum, P, M, N);

	L = 0; R = P - 1;
	while (L < R)
	{
		imin = L;
		imax = L;
		for (int i = L + 1; i < R + 1; i++)
			if (Sum[i] < Sum[imin])
				imin = i;
			else if (Sum[i] > Sum[imax])
				imax = i;
		if (imin != L)
		{
			tmp = Sum[imin];
			Sum[imin] = Sum[L];
			Sum[L] = tmp;
			Swap(Arr3D, M, N, imin, L);
		}

		if (imax != R)
			if (imax == L)
			{
				tmp = Sum[imin];
				Sum[imin] = Sum[R];
				Sum[R] = tmp;
				Swap(Arr3D, M, N, imin, R);
			}
			else
			{
				tmp = Sum[imax];
				Sum[imax] = Sum[R];
				Sum[R] = tmp;
				Swap(Arr3D, M, N, imax, R);
			}
		L = L + 1;
		R = R - 1;
	}

	delete[]Sum;

	time_stop = clock();
	return time_stop - time_start;
}


