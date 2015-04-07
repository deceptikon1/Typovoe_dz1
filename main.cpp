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
		
		company str("ФСО", true);
		cout << "Компания:" << endl << endl;
		str.addworker(Worker("Дмитрий", 19, 30000, 1, true));
		str.addworker(Worker("Александр", 27, 6700, 5, true));
		str.addworker(Worker("Иван", 30, 6300, 10, true));
		//str.addworker(Worker("Александр", 27, 6700, 5, true)); // - проверка исключений

		str.delworkernum(3);
		//str.delworkernum(10);// - проверка исключений

		cout << str;

		str.delworker(Worker("Александр", 27, 6700, 5, true));
		//str.delworker(Worker("Алек", 27, 6700, 5, true)); // - проверка исключений
		str.setcompany("КГБ", false);

		cout << endl << str;

		cout << "Количество рабочих - " << str.getworkersnum() << endl << endl;

		cout << Worker("John", 123, 321, 555, true) + Worker("Sam", 50, 100, 222, false) +
			Worker("Greg", 50, 100, 222, false);

		_getch();
		
	}
	
	catch (const exception & msg)
	{
		cerr << msg.what(); // работет
	}
	_getch();
}