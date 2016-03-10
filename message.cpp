#include <message.h>
#include <iostream>

using namespace std;


Message::Message(const string& newsender, const string& newreceiver, const string& newcontent, const string& newdate){
	sender = new string(newsender);
	receiver = new string(newreceiver);
	content = new string(newcontent);
	date  = new string(newdate);
}

Message::Message(const Message& newmsg){
	sender = new string(*newmsg.sender);
	receiver = new string(*newmsg.receiver);
	content = new string(*newmsg.content);
	date = new string(*newmsg.date);
}

Message::~Message(){
	delete sender;
	delete receiver;
	delete content;
	delete date;
}

bool Message::operator<(const Message& fmsg, const Message& smsg){
	if(*fmsg.date != *smsg.date) return *fmsg.date > *smsg.date;
	else return true;
}

ifstream& operator>>(ifstream& fin, Message& msg){
	fin >> *msg.sender;
	fin >> *msg.receiver;
	fin >> *msg.content;
	fin >> *msg.date;
	return fin;
}

ofstream& operator<<(ofstream& fout, Message& msg){
	fout << *msg.sender << "\n";
	fout << *msg.receiver << "\n";
	fout << *msg.content << "\n";
	fout << *msg.date << "\n";
	return fout;
}

ostream& operator<<(ostream& os, Message& msg){
	os << "Sender : " << *msg.sender << endl;
	os << "Receiver : " << *msg.receiver << endl;
	os << "Content : " << *msg.content << endl;
	os << "Date : " << *msg.date << endl;
	return os;
}