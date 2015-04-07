// Copyright 2015 <Sergey Fedotov>
#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>
#include "company.h";
#include "myexception.cpp"
using namespace std;

int main()
{
	try{
		setlocale(LC_ALL, "rus");
		
		company str("���", true);
		cout << "��������:" << endl << endl;
		str.addworker(Worker("�������", 19, 30000, 1, true));
		str.addworker(Worker("���������", 27, 6700, 5, true));
		str.addworker(Worker("����", 30, 6300, 10, true));
		//str.addworker(Worker("���������", 27, 6700, 5, true)); // - �������� ����������

		str.delworkernum(3);
		//str.delworkernum(10);// - �������� ����������

		cout << str;

		str.delworker(Worker("���������", 27, 6700, 5, true));
		//str.delworker(Worker("����", 27, 6700, 5, true)); // - �������� ����������
		str.setcompany("���", false);

		cout << endl << str;

		cout << "���������� ������� - " << str.getworkersnum() << endl << endl;

		cout << Worker("John", 123, 321, 555, true) + Worker("Sam", 50, 100, 222, false) +
			Worker("Greg", 50, 100, 222, false);

		_getch();
		
	}
	
	catch (const exception & msg)
	{
		cerr << msg.what(); // �������
	}
	_getch();
}