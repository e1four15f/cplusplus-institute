#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Massive
{
public:
	Massive(int size)
	{
		this->size = size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = 0 + rand() % (10 + 0);
		}
	}
	
	Massive(Massive& m)
	{
		size = m.size; 
		data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = m.data[i];
		}
	}
	
	~Massive()
	{
		delete[] data;
	}

	void PrintMassive(int num)
	{
		for (int i = 0; i < size; i++)
		{
			cout << setw(5) << data[i];
			if ((i + 1) % num == 0)
			{
				cout << endl;
			}
		}
		cout << endl;
	}

	int operator ++ (int value)
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			if (data[i] % 2 == 0)
			{
				sum += data[i];
			}
		}
		return sum;
	}

	Massive operator * (Massive& m)
	{
		Sort(*this, this->size);
		Sort(m, m.size);

		PrintMassive(10);
		m.PrintMassive(10);

		int size = 0;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = size; j < m.size; j++)
			{
				if (data[i] == m.data[j])
				{
					size++;
					break;
				}
			}
		}

		Massive massive(size);
		for (int i = 0, size = 0; i < this->size; i++)
		{
			for (int j = size; j < m.size; j++)
			{
				if (data[i] == m.data[j])
				{
					massive.data[size] = data[i];
					size++;
					break;
				}
			}
		}
		return massive;
	}

	int GetSize() { return size; }

	friend void Sort(Massive& m, int size);

private:
	int size;
	int* data;
};

void Sort(Massive& m, int size) 
{
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (m.data[j] > m.data[j + 1]) {
				temp = m.data[j];
				m.data[j] = m.data[j + 1];
				m.data[j + 1] = temp;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	Massive m(20);
	//m.PrintMassive(10);

	cout << m++ << endl;
	
	Massive mm(20);
	//mm.PrintMassive(10);

	Massive mmm = (mm * m);
	mmm.PrintMassive(10);
	
	system("Pause");
	return 0;
}




