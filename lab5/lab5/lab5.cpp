#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip> 

using namespace std;

template <typename T> void RandomArray(T* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 30 + rand() % (100 - 30);
		arr[i] += (T) 0.5;
	}
}

template <typename T> void PrintArray(T* arr, int size, int col)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(6) << arr[i];
		if ((i + 1) % col == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

template <typename T> void SortArray(T& arr, int size)
{
	double temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void SortArray(double* arr, int size)
{
	double temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	int size = 195;
	int col = 15;

	int *arrInt = new int[size];
	RandomArray(arrInt, size);
	cout << "Array of Ints" << endl;
	PrintArray(arrInt, size, col);

	double *arrDouble = new double[size];
	RandomArray(arrDouble, size);
	cout << "Array of Doubles" << endl;
	PrintArray(arrDouble, size, col);

	char *arrChar = new char[size];
	RandomArray(arrChar, size);
	cout << "Array of Chars" << endl;
	PrintArray(arrChar, size, col);

	SortArray(arrInt, size);
	cout << "Sorted Array of Ints" << endl;
	PrintArray(arrInt, size, col);

	SortArray(arrDouble, size);
	cout << "Sorted Array of Doubles" << endl;
	PrintArray(arrDouble, size, col);

	SortArray(arrChar, size);
	cout << "Sorted Array of Chars" << endl;
	PrintArray(arrChar, size, col);

	delete[] arrInt;
	delete[] arrDouble;
	delete[] arrChar;
	system("pause");
	return 0;
}

