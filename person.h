#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>
#include <fstream>

using namespace std;

class Person {
private:
	string* name;
	string* phone;
	string* memo;
public:
	Person(const string&, const string&, const string&);
	Person(const Person&);
	~Person();
	ShowInfo();

	void setName(const string& name);
	void setPhone(const string& phone);
	void setMemo(const string& memo);
	
	ifstream& operator>>(ifstream&, Person&);
	ofstream& operator<<(ofstream&, const Person&);
	ostream& operator<<(ostream&, const Person&):
	Person& operator=(const Person&);
	bool operator==(const Person&);
	bool operator<(const Person&, const Person&);
}

#endif