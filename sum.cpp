#include"sum.h"

void sum(int*** Arr3D, int* Sum, int P, int M, int N)
{
	int tmp;
	for (int i = 0; i < P; i++)
	{
		tmp = 0;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				tmp += Arr3D[i][j][k];
			}
		}
		Sum[i] = tmp;
	}
}