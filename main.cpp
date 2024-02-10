//підключення модулів
#include"print.h"
#include"fill.h"
#include"sort.h"
#include "sum.h"
#include"vector.h"

using namespace std;

void vector()
{
	//оголошення масиву
	int* A;
	int N;
	cout << "Input size: ";
	cin >> N;
	A = new int[N];


	//вибір того, як заповнювати масив
	cout << "Choose the option(type the digit):" << endl;
	cout << "1. Sorted" << endl;
	cout << "2. Random" << endl;
	cout << "3. Reversed" << endl;
	int option;
	cin >> option;
	switch (option)
	{
		//впорядкований
		case 1: for(int i = 0; i < N; i++)
				{
					A[i] = i;
				}
			break;
		//невпорядкований
		case 2: for (int i = 0; i < N; i++)
				{
					A[i] = rand() % N;
				}
			break;
		//оберенено впорядкований
		case 3: for (int i = 0; i < N; i++)
				{
					A[i] = N - i;
				}
			break;
		default: cout << "Incorrect data!" << endl;
	}

	//вибір алгоритму сортування
	cout << "Choose the option(type the digit):" << endl;
	cout << "1. Quick sort" << endl;
	cout << "2. Select 5" << endl;
	cout << "3. Select 8" << endl;
	cin >> option;
	switch (option)
	{
		case 1: cout << "time = " << Vtime_quick_sort(N, A, 0, N - 1) << endl;
			break;
		case 2: cout << "time = " << VSelect5(A, N) << endl;
			break;
		case 3: cout << "time = " << VSelect8(A, N) << endl;
			break;
		default: cout << "Incorrect data!" << endl;
	}
}


void D3()
{
	//оголошення масиву
	int P, M, N;
	int*** Arr3D;

	cout << "Input size:" << endl;
	cout << "P: ";
	cin >> P;
	cout << "M: ";
	cin >> M;
	cout << "N: ";
	cin >> N;

	//виділення пам'яті для масиву
	Arr3D = new int** [P];
	for (int i = 0; i < P; i++)
		Arr3D[i] = new int* [M];
	for (int i = 0; i < P; i++)
		for (int j = 0; j < M; j++)
			Arr3D[i][j] = new int[N];

	//вибір того, як заповнювати масив
	cout << "Choose the option(type the digit):" << endl;
	cout << "1. Sorted" << endl;
	cout << "2. Random" << endl;
	cout << "3. Reversed" << endl;
	int option;
	cin >> option;
	switch (option)
	{
		//впорядкований
		case 1: fill_sorted(Arr3D, P, M, N);
				break;
		//невпорядкований
		case 2: fill_random(Arr3D, P, M, N);
				break;
		//оберенено впорядкований
		case 3: fill_reversed(Arr3D, P, M, N);
				break;
		default: cout << "Incorrect data!" << endl;
	}

	//вибір алгоритму сортування
	cout << "Choose the option(type the digit):" << endl;
	cout << "1. Quick sort" << endl;
	cout << "2. Select 5" << endl;
	cout << "3. Select 8" << endl;
	cin >> option;
	switch (option)
	{
	case 1: cout << "time = " << timeQuickSort(0, P-1, Arr3D, P, M, N) << endl;
		break;
	case 2: cout << "time = " << Select5(Arr3D, P, M, N) << endl;
		break;
	case 3: cout << "time = " << Select8(Arr3D, P, M, N) << endl;
		break;
	default: cout << "Incorrect data!" << endl;
	}

	//очищення пам'яті
	for (int i = 0; i < P; i++)
		for (int j = 0; j < M; j++)
			delete[]Arr3D[i][j];
	for (int i = 0; i < P; i++)
		delete[]Arr3D[i];
	delete[]Arr3D;
}

void All()
{
	int P = 50000, M, N;
	int*** Arr3D;

	Arr3D = new int** [P];

	//масив, в який записуємо дані зі всіх випадків
	int tmp[3][3]{};

	//підраховуємо значення та записуємо в масив tmp
	for (int i = 1; i <= 16; i += i)
	{
		M = i;
		N = i;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

			fill_sorted(Arr3D, P, M, N);
		tmp[0][0] += timeQuickSort(0, P - 1, Arr3D, P, M, N);
			fill_random(Arr3D, P, M, N);
		tmp[0][1] += timeQuickSort(0, P - 1, Arr3D, P, M, N);
			fill_reversed(Arr3D, P, M, N);
		tmp[0][2] += timeQuickSort(0, P - 1, Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}

	for (int i = 1; i <= 16; i += i)
	{

		M = i;
		N = i;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];



			fill_sorted(Arr3D, P, M, N);
		tmp[1][0] += Select5(Arr3D, P, M, N);
			fill_random(Arr3D, P, M, N);
		tmp[1][1] += Select5(Arr3D, P, M, N);
			fill_reversed(Arr3D, P, M, N);
		tmp[1][2] += Select5(Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}

	for (int i = 1; i <= 16; i += i)
	{
		M = i;
		N = i;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

			fill_sorted(Arr3D, P, M, N);
		tmp[2][0] += Select8(Arr3D, P, M, N);
			fill_random(Arr3D, P, M, N);
		tmp[2][1] += Select8(Arr3D, P, M, N);
			fill_reversed(Arr3D, P, M, N);
		tmp[2][2] += Select8(Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}

	P = 32000;

	for (int s = 2, r = 800; s <= 16; s += s, r /= 2)
	{
		M = s;
		N = r;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

			fill_sorted(Arr3D, P, M, N);
		tmp[0][0] += timeQuickSort(0, P - 1, Arr3D, P, M, N);
			fill_random(Arr3D, P, M, N);
		tmp[0][1] += timeQuickSort(0, P - 1, Arr3D, P, M, N);
			fill_reversed(Arr3D, P, M, N);
		tmp[0][2] += timeQuickSort(0, P - 1, Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}
	for (int s = 2, r = 800; s <= 16; s += s, r /= 2)
	{
		M = r;
		N = s;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

		fill_sorted(Arr3D, P, M, N);
		tmp[0][0] += timeQuickSort(0, P - 1, Arr3D, P, M, N);
		fill_random(Arr3D, P, M, N);
		tmp[0][1] += timeQuickSort(0, P - 1, Arr3D, P, M, N);
		fill_reversed(Arr3D, P, M, N);
		tmp[0][2] += timeQuickSort(0, P - 1, Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}
	for (int s = 2, r = 800; s <= 16; s += s, r /= 2)
	{
		M = s;
		N = r;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

		fill_sorted(Arr3D, P, M, N);
		fill_sorted(Arr3D, P, M, N);
		tmp[1][0] += Select5(Arr3D, P, M, N);
		fill_random(Arr3D, P, M, N);
		tmp[1][1] += Select5(Arr3D, P, M, N);
		fill_reversed(Arr3D, P, M, N);
		tmp[1][2] += Select5(Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}
	for (int s = 2, r = 800; s <= 16; s += s, r /= 2)
	{
		M = r;
		N = s;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

		fill_sorted(Arr3D, P, M, N);
		fill_sorted(Arr3D, P, M, N);
		tmp[1][0] += Select5(Arr3D, P, M, N);
		fill_random(Arr3D, P, M, N);
		tmp[1][1] += Select5(Arr3D, P, M, N);
		fill_reversed(Arr3D, P, M, N);
		tmp[1][2] += Select5(Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}
	for (int s = 2, r = 800; s <= 16; s += s, r /= 2)
	{
		M = s;
		N = r;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

		fill_sorted(Arr3D, P, M, N);
		fill_sorted(Arr3D, P, M, N);
		tmp[2][0] += Select8(Arr3D, P, M, N);
		fill_random(Arr3D, P, M, N);
		tmp[2][1] += Select8(Arr3D, P, M, N);
		fill_reversed(Arr3D, P, M, N);
		tmp[2][2] += Select8(Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}
	for (int s = 2, r = 800; s <= 16; s += s, r /= 2)
	{
		M = r;
		N = s;

		for (int i = 0; i < P; i++)
			Arr3D[i] = new int* [M];
		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				Arr3D[i][j] = new int[N];

		fill_sorted(Arr3D, P, M, N);
		fill_sorted(Arr3D, P, M, N);
		tmp[2][0] += Select8(Arr3D, P, M, N);
		fill_random(Arr3D, P, M, N);
		tmp[2][1] += Select8(Arr3D, P, M, N);
		fill_reversed(Arr3D, P, M, N);
		tmp[2][2] += Select8(Arr3D, P, M, N);

		for (int i = 0; i < P; i++)
			for (int j = 0; j < M; j++)
				delete[]Arr3D[i][j];
		for (int i = 0; i < P; i++)
			delete[]Arr3D[i];
	}

	//ділимо отриманні значення на 13(кількість тестів), щоб отримати середнє арифметичне
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp[i][j] /= 13;

	//виводимо таблицю з результатами
	cout << "-------------------------------------------" << endl;
	cout << "|            | Sorted | Random | Reversed |" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "| Quick sort |" << setw(5) <<   tmp[0][0]  << setw(4) << "|" << setw(5) << tmp[0][1] << setw(4) << "|"<< setw(6) << tmp[0][2] << setw(5) << "|" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "| Select 5   |" << setw(5) << tmp[1][0] << setw(4) << "|" << setw(5) << tmp[1][1] << setw(4) << "|" << setw(6) << tmp[1][2] << setw(5) << "|" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "| Select 8   |" << setw(5) << tmp[2][0] << setw(4) << "|" << setw(5) << tmp[2][1] << setw(4) << "|" << setw(6) << tmp[2][2] << setw(5) << "|" << endl;
	cout << "-------------------------------------------" << endl;
	
	delete[]**Arr3D;
}

void menu()
{
	int option;
	//цикл для повторного введення даних
	while (true)
	{
		cout << "----------------------------------" << endl;
		cout << "Choose the option(type the digit):" << endl;
		cout << "1. Vector" << endl;
		cout << "2. 3D" << endl;
		cout << "3. All" << endl;
		cout << "4. Exit" << endl;

		cin >> option;
		switch (option)
		{
			//перший випадок одновимірний масив
			case 1: vector();
				break;
			//другий випадок тривімірний масив
			case 2: D3();
				break;
			//тест всіх випадків одночасно
			case 3: All();
				break;
			//вихід з меню
			case 4: return;
				break;
			default: cout << "Incorrect data!" << endl;
				break;
		}
	}
}

int main()
{
	srand(time(0));

	//меню для вибору функцій програми
	menu();
}