#include "fill.h"

//впорядкований
void fill_sorted(int*** Arr3D, int P, int M, int N)
{
	int number = 0;
	for (int k = 0; k < P; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
				Arr3D[k][i][j] = number++;
}
//оберенено впорядкований
void fill_reversed(int*** Arr3D, int P, int M, int N)
{
	int number = P*M*N;
	for (int k = 0; k < P; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
				Arr3D[k][i][j] = number--;
}
//невпорядкований
void fill_random(int*** Arr3D, int P, int M, int N)
{
	for (int k = 0; k < P; k++)
		for (int j = 0; j < N; j++)
			for (int i = 0; i < M; i++)
				Arr3D[k][i][j] = rand() % P * M * N;
}