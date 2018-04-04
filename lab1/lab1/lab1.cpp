#include "stdafx.h"
#include <iostream>
#include <iomanip>
#define n 10

using namespace std;

struct passport
{
	char name[20];
	char surname[20];
	int birthYear;
} *pPassports;

void AddPassport(passport *p) 
{
	cout << "Name[20]: ";
	cin >> p->name;
	cout << "Surname[20]: ";
	cin >> p->surname;
	cout << "Birth Year: ";
	cin >> p->birthYear;
}

void PrintPassports(passport pPassports[], int size) 
{
	cout << setw(20) << "Name" << setw(20) << "Surname" << setw(20)
		<< "Birth Year" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(20) << pPassports[i].name << setw(20) << pPassports[i].surname 
			<< setw(20) << pPassports[i].birthYear << endl;
	}
}

void PrintPassportsWithSameSurname(passport pPassports[], int size)
{
	cout << setw(20) << "Name" << setw(20) << "Surname" << setw(20)
		<< "Birth Year" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			if (strcmp(pPassports[i].surname, pPassports[j].surname) == 0 && i != j)
			{
				cout << setw(20) << pPassports[i].name << setw(20) << pPassports[i].surname
					<< setw(20) << pPassports[i].birthYear << endl;
				break;
			}
		}
	}
}

void PrintPassportsUnderYear(passport pPassports[], int size, int birthYear)
{
	cout << setw(20) << "Name" << setw(20) << "Surname" << setw(20)
		<< "Birth Year" << endl;
	cout << "------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		if (pPassports[i].birthYear < birthYear) 
		{
		cout << setw(20) << pPassports[i].name << setw(20) << pPassports[i].surname
			<< setw(20) << pPassports[i].birthYear << endl;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	pPassports = new passport[n];
	
	int size = 0;
	char answer = 'y';
	for (passport *p = pPassports; p < pPassports + n; p++)
	{
		cout << "Add new passport? [y]\n";
		cin >> answer;
		if (answer != 'y')
		{
			break;
		}
		AddPassport(p);
		size++;
	}
	cout << "\nAll passports" << endl;
	PrintPassports(pPassports, size);
	
	int year;
	cout << "\nPassports under birth year: " << endl;
	cin >> year;
	PrintPassportsUnderYear(pPassports, size, year);

	cout << "\nPassports with same surname: " << endl;
	PrintPassportsWithSameSurname(pPassports, size);

	delete pPassports;
	system("Pause");
	return 0;
}


