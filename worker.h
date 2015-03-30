#include <iostream>
using namespace std;
class Worker
{
	char name[64]; 
	int age; 	
	int salary; 
	int exp; 
	bool goodworker; 	
public:
	Worker();
	Worker(char* name, int age, int salary, int exp,bool goodworker);
	Worker(char* name, int age);
	
	~Worker();
	
	void reworker(char* name, int age, int salary,int exp,bool goodworker);
	void rename(char* name);
	void reage(int age);
	void resalary(int salary);
	char *getname();
	
	friend ostream & operator <<(ostream& stream, Worker& buf);
	Worker operator =(Worker& buf);
	bool Worker::operator==( Worker& buf);
};