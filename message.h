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
	string* date;
public:
	Message(const string&, const string&, const string&, const string&);
	Message(const Message&);
	~Message();

	bool operator<(const Message&, const Message&);

	friend ifstream& operator>>(ifstream&, Message&);
	friend ofstream& operator<<(ofstream&, const Message&);
	friend ostream& operator<<(ostream&, const Message&);
}

#endif