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
		//��� ����� ���� warning �� ��, ��� �� ������������
		//strcpy_s. �� ��� ������������� �������� ������. ��� ��� ��������� ������� � 2-�� �����������.
		//��� � ������� � ����������
	}
	~String()
	{
		delete[]stroka;
		cout << "������ ������� �������" << endl;
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
	String s("�������� ������� �����");
	s.print();
	*/

	char co[2];
	char cn[2];

	strcpy_s(cn, strlen(co), co);

































	system("pause");
	return 0;
}