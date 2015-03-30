#pragma warning(disable:4996)
#include "worker.h"

Worker::Worker()
{
	char* name = 0;
	int age = 0;
	int exp = 0;
	int salary = 0;
	bool goodworker = false;
}

Worker::Worker(char name[64], int age, int exp, int salary, bool goodworker)
{
	strcpy(this->name, name);
	this->age = age;
	this->exp = exp;
	this->salary = salary;
	this->goodworker = goodworker;
}

Worker::Worker(char name[64], int age)
{
	strcpy(this->name, name);
	this->age = age;
	exp = 0;
	salary = 0;
	goodworker = false;
}


Worker::~Worker()
{
	char* name = 0;
	int age = 0;
	int exp = 0;
	int salary = 0;
	bool goodworker = false;
}

void Worker::reworker(char name[64],int age,int exp,int salary,bool goodworker)
{
	strcpy(this->name, name);
	this->age = age;
	this->exp = exp;
	this->salary = salary;
	this->goodworker = goodworker;
}

char* Worker::getname()
{
	return name;
}

Worker Worker::operator =(Worker & buf)
{
	strcpy(name, buf.name);
	age = buf.age;
	salary = buf.salary;
	goodworker = buf.goodworker;
	return *this;
}

 ostream & operator <<(ostream & stream, Worker& buf)
{
	stream << "Работник " << buf.name << ",возраст " << buf.age << ",зарплата " << buf.exp << ",стаж " << buf.salary << ",качество работы ";
	if (buf.goodworker)
		stream << "хорошее" << endl;
	else stream << "плохое" << endl;
	return stream;
}

 bool Worker::operator==( Worker & buf)
 {
	 if (this->name == buf.name && this->age == buf.age && this->salary == buf.salary &&
		 this->exp == buf.exp && this->goodworker == buf.goodworker)
		 return true;
	 else
		 return false;
 }