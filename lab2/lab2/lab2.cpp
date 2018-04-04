#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Car 
{
private:
	static int count;
	char* brand;
	char* surname;
	int power;
	int mileage;

public:
	Car()
	{
		//cout << "Constructor default " << this << endl;
		brand = new char[20] {};
		surname = new char[20] {};
		power = mileage = 0;
	}

	Car(const Car &car)
	{
		//cout << "Constructor copy " << this << endl;
		this->brand = new char[20];
		strcpy_s(this->brand, strlen(car.brand) + 1, car.brand);
		this->surname = new char[20];
		strcpy_s(this->surname, strlen(car.surname) + 1, car.surname);
		this->power = car.power;
		this->mileage = car.mileage;
	}
	
	Car(char* brand, char* surname, int power, int mileage)
	{
		//cout << "Constructor with params " << this << endl;
		this->brand = new char[strlen(brand) + 1];
		strcpy_s(this->brand, strlen(brand) + 1, brand);
		this->surname = new char[strlen(surname) + 1];
		strcpy_s(this->surname, strlen(surname) + 1, surname);
		this->power = power;
		this->mileage = mileage;
		count++;
	}
	
	~Car()
	{
		//cout << "Destructor " << this << endl;
		delete[] brand;
		delete[] surname;
	}

	void Define(char* brand, char* surname, int power, int mileage)
	{
		cout << "Define " << this << endl;
		this->brand = new char[20];
		strcpy_s(this->brand, strlen(brand) + 1, brand);
		this->surname = new char[20];
		strcpy_s(this->surname, strlen(surname) + 1, surname);
		this->power = power;
		this->mileage = mileage;
	}
	
	void Scan() 
	{
		cout << "Add new car" << endl;
		char str[20];
		cout << "Brand: ";
		cin >> str;
		brand = new char[20];
		strcpy_s(brand, strlen(str) + 1, str);
		cout << "Surname: ";
		cin >> str;
		surname = new char[20];
		strcpy_s(surname, strlen(str) + 1, str);
		cout << "Power: ";
		cin >> power;
		cout << "Mileage: ";
		cin >> mileage;
	}

	void Display()
	{
		cout << setw(20) << brand << setw(20) << surname <<
			setw(20) << power << setw(20) << mileage << endl;
	}

	char* GetBrand() { return brand; }
	char* GetSurname() { return surname; }
	int GetPower() { return power; }
	int GetMileage() { return mileage; }
	int GetCount() { return count; }
};
int Car::count = 0;

void DisplayAllCars(Car *cars, int size)
{
	cout << setw(20) << "Brand" << setw(20) << "Surname" <<
		setw(20) << "Power" << setw(20) << "Mileage" << endl;
	for (int i = 0; i < size; i++)
	{
		cars[i].Display();
	}
}

void AddCar(Car *&cars, int &size, Car newCar)
{
	Car *newCars = new Car[size + 1];
	for (int i = 0; i < size; i++)
	{
		new (&newCars[i]) Car(cars[i]);
	}
	new (&newCars[size]) Car(newCar);
	size++;
	delete[] cars;
	cars = newCars;
}

int SumOfMileage(Car *cars, char *surname, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(cars[i].GetSurname(), surname) == 0)
		{
			sum += cars[i].GetMileage();
		}
	}

	return sum;
}

Car* CarsPowerAbove(Car *cars, int &size, int power)
{
	int newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (cars[i].GetPower() > power)
		{
			newSize++;
		}
	}

	Car *newCars = new Car[newSize];
	for (int i = 0, current = 0; i < size; i++)
	{
		if (cars[i].GetPower() > power)
		{
			new (&newCars[current]) Car(cars[i]);
			current++;
		}
	}

	size = newSize;
	return newCars;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int size = 2;	
	Car *cars = new Car[size];

	new (&cars[0]) Car("HAHA", "SSSST", 300, 322);
	new (&cars[1]) Car("HasdsadAHA", "SasdSSST", 1432, 32412);
	//DisplayAllCars(cars, size);
	AddCar(cars, size, Car("JIJI", "ASDT", 200, 33322));
	DisplayAllCars(cars, size); 

	
	char answer = 'y';
	while (true) 
	{
		cout << "Add new car? [y]" << endl;
		cin >> answer;

		if (answer != 'y') {
			break;
		}

		Car temp = Car();
		temp.Scan();
		AddCar(cars, size, temp);
	}
	
	DisplayAllCars(cars, size);

	char surname[20]; 
	cout << "Enter surname: ";
	cin >> surname;
	cout << "Sum Of Mileage: " << SumOfMileage(cars, surname, size) << endl;
	
	int power;
	int newSize = size;
	cout << "Enter power: ";
	cin >> power;
	Car *newCars = CarsPowerAbove(cars, newSize, power);
	DisplayAllCars(newCars, newSize);
	
	delete[] newCars;
	delete[] cars;
	system("Pause");
	return 0;
}




