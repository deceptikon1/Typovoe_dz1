#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "company.h";
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");

	company str("���", true);
	cout << "��������:" << endl << endl;
	    str.addworker(Worker("�������", 19, 30000, 1, true));
		str.addworker(Worker("���������", 27, 6700, 5, true));
		str.addworker(Worker("����", 30, 6300, 10, true));
	
		cout << str;
		
    str.delworker("���������");
    str.recompany("���", false);
	 
    cout<<endl << str;

	cout <<"���������� ������� - "<< str.getworkersnum() << endl<<endl;

	cout << Worker("John", 123, 321, 555, true) + Worker("Sam", 50, 100, 222, false) +
		 Worker("Greg", 50, 100, 222, false); 

	_getch();
}