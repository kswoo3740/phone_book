#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <vector>
#include <person.h>

using namespace std;

class PhoneBook{
private:
	vector<Person> people;
public:
	void readFile(const string&);
	void saveFile(const string&);
	
	void sorting();
	void addPerson(const Person&);
	void removePerson(const Person&);

	int PeopleOfPhoneBook();
	void showPhoneBook();
	
	Person findName(const string& fPhone);
	Person findPhone(const string& fName);
}

#endif

