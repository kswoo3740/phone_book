#ifndef MESSAGESTORE_H
#define MESSAGESTORE_H

#include <string>
#include <ostream>
#include <fstream>
#include <vector>
#include <message.h>

using namespace std;

class MessageStore {
private:
	vector<Message> sms; 
public:
	void readFile(const string&);
	void saveFile(const string&);

	void msgSorting();
	void addMsg(const Message&);
	void removeMsg(const Message&);
	Message findMsg(const string&);

}

#endif