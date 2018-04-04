#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;
/*
class String
{
private:
	char *stroka;
public:
	String()
	{
		stroka = new char[0];
	}
	String(char *s)
	{
		stroka = new char[strlen(s) + 1];
		//strcpy_s(stroka, sizeof(), s);
		//Вот сдесь идет warning на то, что бы использовать
		//strcpy_s. Но при использовании вылетает ошибка. что нет прототипа функции с 2-мя параметрами.
		//Вот я немного и озадачился
	}
	~String()
	{
		delete[]stroka;
		cout << "Строка успешно удалена" << endl;
	}
	void print()
	{
		cout << stroka << endl;
	}
};
*/

int main()
{
	/*
	String s("Точность превыше всего");
	s.print();
	*/

	char co[2];
	char cn[2];

	strcpy_s(cn, strlen(co), co);

































	system("pause");
	return 0;
}