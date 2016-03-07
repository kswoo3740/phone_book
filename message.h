#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ostream>
#include <fstream>

using namespace std;

class Message {
private:
	string* sender;
	string* receiver;
	string* content;
	int date;
public:
	Message(const string&, const string&, const string&, const int);
	Message(const Message&);
	~Message();

	bool operator<(const Message&, const Message&);

	ifstream& operator>>(ifstream&, Message&);
	ofstream& operator<<(ofstream&, const Message&);
	ostream& operator<<(ostream&, const Message&);
}

#endif