#include "stdafx.h"
#include <iostream>

using namespace std;

class Automobile
{
public:
	char* brandOfGasoline;

	Automobile()
	{
		brandOfGasoline = new char[20] {};
		tankCapacity = enginePower = 0;
	}

	~Automobile()
	{
		delete[] brandOfGasoline;
	}

	virtual void Show() = 0;

	int getEnginePower() { return enginePower; }

	void setBrandOfGasoline(char* brandOfGasoline)
	{
		delete[] this->brandOfGasoline;
		this->brandOfGasoline = new char[strlen(brandOfGasoline) + 1] {};
		strcpy_s(this->brandOfGasoline, strlen(brandOfGasoline) + 1, brandOfGasoline);
	}

	void setEnginePower(int enginePower) 
	{
		this->enginePower = enginePower;
	}

	void setTankCapacity(int tankCapacity)
	{
		this->tankCapacity = tankCapacity;
	}

protected: 
	int tankCapacity;

private:
	int enginePower;
};

class Car : public Automobile
{
public: 
	int numberOfDoors;
	int numberOfPassengers;

	Car()
	{
		brandOfCar = new char[20] {};
		numberOfDoors = numberOfPassengers = 0;
	}

	Car(char* brandOfCar, int numberOfDoors, int numberOfPassengers)
	{
		this->brandOfCar = new char[strlen(brandOfCar) + 1] {};
		strcpy_s(this->brandOfCar, strlen(brandOfCar) + 1, brandOfCar);
		this->numberOfDoors = numberOfDoors;
		this->numberOfPassengers = numberOfPassengers;
	}

	~Car()
	{
		delete[] brandOfCar;
	}

	void Show() override
	{
		cout << "This is Car" << endl;
		cout << "Brand Of Gasoline: " << brandOfGasoline << endl;
		cout << "Tank Capacity: " << tankCapacity << endl;
		cout << "Engine Power: " << getEnginePower() << endl;
		cout << "Brand Of Car: " << brandOfCar << endl;
		cout << "Number Of Doors: " << numberOfDoors << endl;
		cout << "Number Of Passengers: " << numberOfPassengers << endl;
	}

private:
	char* brandOfCar;
};

class Truck : public Automobile
{
public:
	Truck()
	{
		carrying = 0;
	}

	Truck(int carrying)
	{
		this->carrying = carrying;
	}

	void Show() override
	{
		cout << "This is Truck" << endl;
		cout << "Brand Of Gasoline: " << brandOfGasoline << endl;
		cout << "Tank Capacity: " << tankCapacity << endl;
		cout << "Engine Power: " << getEnginePower() << endl;
		cout << "Carrying: " << carrying << endl;
		cout << "Brand Of Gasoline: " << brandOfGasoline << endl;
	}

private:
	int carrying;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Car c("ADASD", 151, 1515);
	c.setBrandOfGasoline("afagag");
	c.setEnginePower(15251);
	c.setTankCapacity(2345);
	c.Show();

	cout << "-----------------------" << endl;

	Truck t(124);
	t.setBrandOfGasoline("sdf");
	t.setEnginePower(12214);
	t.setTankCapacity(123);
	t.Show();

	system("pause");
	return 0;
}
