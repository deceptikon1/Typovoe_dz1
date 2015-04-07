// Copyright 2015 <Sergey Fedotov>
#pragma once
#include "Worker.h"
#include <list>
	
class company  
{
	std::list < Worker > list; 
	string name;
	int workers;
	bool gooddepart;
public:
	company();
	company(const string& name ,const bool& gooddepart);
	company(const company& buf);

	~company();

	void addworker(const Worker& buf);

	void delworker(const Worker& wrk);
	void delworkernum(const int& i);
	
	void setcompany(const string& name,const bool& gooddepart);
	void setdepartname(const string& name);
	void setgooddepart(const bool& gooddepart);

	const int& getworkersnum();
	const bool& getgooddepart();
	const string& getdepartname();
    const Worker& getworker(const int& i);

	const bool hasworker(const Worker& wrk);
	const Worker& find(const Worker& wrk);
	
	friend company & operator +(const Worker& buf1,const  Worker& buf2);
	friend company & operator +(company& buf1, const Worker& buf2);
	const company& operator =(const company& buf);
	const bool& operator ==(const company& buf);
	friend ostream & operator <<(ostream & stream, company& buf);
};