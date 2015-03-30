#pragma warning(disable:4996)
#include <list>
#include "company.h"


company::company() : list()
{
	char *name = 0;
	int workers = 0;
	bool gooddepart = false;
}

company::company(char name[64], bool gooddepart) :list()
{
	strcpy(this->name,name);
	int workers = 0;
	this->gooddepart = gooddepart;
}

company::~company()
{
	char *name = 0;
	int workers = 0;
	bool gooddepart = false;
}

void company::addworker(Worker & buf)
{
	workers++;
	list.insert(list.end(), buf);
}

void company::delworker(char * name)
{
	std::list<Worker>::iterator iter = this->find(name);
	iter == list.end(); 
	list.erase(iter);
	workers--;
}

void company::recompany(char name[64],bool gooddepart)
{
	strcpy(this->name, name);
	this->gooddepart = gooddepart;
}

char* company::getdepartname()
{
	return name;
}

int company::getworkersnum()
{
	return workers;
}

std::list<Worker>::iterator company::find(char* wrk)
{
	std::list<Worker>::iterator iter = list.begin();
		while (iter != list.end())
		{
			if (!strcmp(iter->getname(),wrk))
			{
				return iter;
			}
			iter++;
		}
		return list.end();
}

company & operator +(Worker & buf1, Worker & buf2)
{
	company *one;
	one = new company("New company ",true);
	one->addworker(buf1);
	one->addworker(buf2);

	return *one;
}

company & operator +(company & buf1, Worker & buf2)
{
	buf1.addworker(buf2);
	return buf1;
}

ostream & operator <<(ostream & stream, company& str) 
{
	stream << "Отдел " << str.name<< ", качество работы - ";
	if (str.gooddepart)
		stream << "хорошее" << endl<<endl;
	else stream << "плохое" << endl<<endl;

	for (list<Worker>::iterator i = str.list.begin(); i != str.list.end(); i++)
	{
		stream<<*i;
	}
	return stream;
}