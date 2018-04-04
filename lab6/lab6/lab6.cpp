#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class Employe
{
public:
	enum Position { DEVELOPER, ENGINEER, ASSISTANT};

	class FullName
	{
	public:
		char* name;
		char* surname;
		char* patronymic;

		FullName() {}

		FullName(char* name, char* surname, char* patronymic)
		{
			this->name = new char[strlen(name) + 1] {};
			strcpy_s(this->name, strlen(name) + 1, name);

			this->surname = new char[strlen(surname) + 1] {};
			strcpy_s(this->surname, strlen(surname) + 1, surname);

			this->patronymic = new char[strlen(patronymic) + 1] {};
			strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);
		}

		~FullName()
		{
			delete[] name;
			delete[] surname;
			delete[] patronymic;
		}

		FullName& operator = (const FullName& fullName)
		{
			this->name = new char[strlen(fullName.name) + 1] {};
			strcpy_s(this->name, strlen(fullName.name) + 1, fullName.name);

			this->surname = new char[strlen(fullName.surname) + 1] {};
			strcpy_s(this->surname, strlen(fullName.surname) + 1, fullName.surname);

			this->patronymic = new char[strlen(fullName.patronymic) + 1] {};
			strcpy_s(this->patronymic, strlen(fullName.patronymic) + 1, fullName.patronymic);

			return *this;
		}
	};

	Employe(){}

	Employe(FullName& fullName, Position position, char* theme)
	{
		this->fullName = fullName;
	
		this->position = position;

		this->theme = new char[strlen(theme) + 1] {};
		strcpy_s(this->theme, strlen(theme) + 1, theme);
	}

	Employe(Employe& employe) : 
		Employe(employe.fullName, employe.position, employe.theme) {}

	~Employe()
	{
		delete[] theme;
	}

	void Show()
	{
		cout << setw(15) << left << "Name: " << setw(15) << fullName.name << endl;
		cout << setw(15) << left << "Surname: " << setw(15) << fullName.surname << endl;
		cout << setw(15) << left << "Patronymic: " << setw(15) << fullName.patronymic << endl;
		cout << setw(15) << left << "Position: " << setw(15) << position << endl;
		cout << setw(15) << left << "Theme: " << setw(15) << theme << endl;
	}

	void Save()
	{
		ofstream fout("output.txt", ios_base::app);
		fout << fullName.name << endl;
		fout << fullName.surname << endl;
		fout << fullName.patronymic << endl;
		fout << position << endl;
		fout << theme << endl;
		fout.close();
	}

private:
	FullName fullName;
	Position position;
	char* theme;
};

class EmployeList
{
public:
	Employe* employes;
	int size;

	EmployeList()
	{
		size = 0;
		employes = new Employe[size];
	}

	~EmployeList()
	{
		delete[] employes;
	}

	void Add(Employe employe)
	{
		Employe* newEmployes = new Employe[size + 1];
		for (int i = 0; i < size; i++)
		{
			new (&newEmployes[i]) Employe(employes[i]);
		}
		new (&newEmployes[size]) Employe(employe);
		size++;
		delete[] employes;
		employes = newEmployes;
	}

	void Show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ")" << endl;
			employes[i].Show();
		}
		cout << "+--------------------------------+" << endl;
	}

	void Save()
	{
		ofstream fout("output.txt", ios_base::app);
		for (int i = 0; i < size; i++)
		{
			fout << i + 1 << ")" << endl;
			employes[i].Save();
		}
		fout.close();
	}
};

class ThemeList
{

};

class Department
{
public:
	Department()
	{
		name = new char[20];
		head = new char[20];
	}

	Department(char* name, char* head)
	{
		this->name = new char[strlen(name) + 1] {};
		strcpy_s(this->name, strlen(name) + 1, name);

		this->head = new char[strlen(head) + 1] {};
		strcpy_s(this->head, strlen(head) + 1, head);
	}

	~Department()
	{
		delete[] name;
		delete[] head;
	}

	void Add(Employe& employe)
	{
		list.Add(employe);
		employeesCount++;
	}

	void Show()
	{
		cout << "+--------------------------------+" << endl;
		cout << "Department name: " << name << endl;
		cout << "Head Of Department :" << head << endl;
		cout << "Employees Count: " << employeesCount << endl; 
		cout << "+--------------------------------+" << endl;
		list.Show();
	}

	void Save()
	{
		ofstream fout("output.txt");
		fout << name << endl;
		fout << head << endl;
		fout << employeesCount << endl;
		fout.close();
		list.Save(); 
	}

	void Load()
	{
		ifstream fin("input.txt");
		char buff[50];
		fin >> buff;
		name = buff;
		fin >> buff;
		head = buff;
		fin >> buff;
		employeesCount = (int)buff;
		fin.close();
	}

private:
	char* name;
	char* head;
	static int employeesCount;
	EmployeList list;
};
int Department::employeesCount = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	Department d;
	d.Load();
	d.Show();
	/*
	Employe e1(Employe::FullName("Hideo", "Kadzima", "HahA"), 
		Employe::Position::DEVELOPER, "MGS5");

	Department d("Hui", "Hssss");
	d.Add(e1);
	d.Add(e1);
	d.Add(e1);
	d.Add(e1);
	d.Show();

	d.Save();
	*/

	system("pause");
	return 0;
}

