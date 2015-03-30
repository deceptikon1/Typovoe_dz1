#include "Worker.h"
#include <list>
	
class company  
{
	std::list < Worker > list; 

	char name[64];
	int workers;
	bool gooddepart;
public:
	company();
	company(char* name ,bool gooddepart);

	~company();

	void addworker(Worker& buf);
	void delworker(char * name);
	void recompany(char* name,bool gooddepart);
	int getworkersnum();
	char *getdepartname();

	std::list<Worker>::iterator find(char* name);
	
	friend company & operator +(Worker& buf1, Worker& buf2);
	friend company & operator +(company& buf1, Worker& buf2);
	company operator =(company& buf);
	friend ostream & operator <<(ostream & stream, company& buf);
};