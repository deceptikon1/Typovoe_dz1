#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "company.h";
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");

	company str("ФСО", true);
	cout << "Компания:" << endl << endl;
	    str.addworker(Worker("Дмитрий", 19, 30000, 1, true));
		str.addworker(Worker("Александр", 27, 6700, 5, true));
		str.addworker(Worker("Иван", 30, 6300, 10, true));
	
		cout << str;
		
    str.delworker("Александр");
    str.recompany("КГБ", false);
	 
    cout<<endl << str;

	cout <<"Количество рабочих - "<< str.getworkersnum() << endl<<endl;

	cout << Worker("John", 123, 321, 555, true) + Worker("Sam", 50, 100, 222, false) +
		 Worker("Greg", 50, 100, 222, false); 

	_getch();
}