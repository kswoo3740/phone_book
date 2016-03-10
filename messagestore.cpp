#include <messagestore.h>
#include <message.h>
#include <iostream>
#include <vector>

using namespace std;

void MessageStore::readFile(const string& filename){
	ifstream fin(filename.c_str());
	Message msg;
	while(fin.is_open()){
		fin>>msg;
		messages.push_back();
	}
}

void MessageStore::saveFile(const string& filename){
	ofstream fout(filename.c_str());
	vector<Message>::iterator it;
	for(it=Messages.begin();it!=Messages.end();it++) fout<<*it;
}

void MessageStore::msgSorting(){
	sort(messages.begin(), messages.end());
}

void MessageStore::addMsg(const Messages& msg){
	messages.push_back(msg);
	sorting();
}

void MessageStore::removeMsg(const Message& msg){
	vector<Message>::iterator it;
	int i=0;
	for(it=messages.begin();it!=messages.end();it++){
		if(strcmp(*it.sender,msg.sender)==strcmp(*it.receiver,msg.receiver)==strcmp(*it.content,msg.content)==strcmp(*it.date,msg.date)) break;
			i++;
	}
	messages.erase(messages.begin+i);
}

MessageStore MessageStore::findMsg(const string& fPerson){
	vector<Message>::iterator it;
	MessageStore fResult;
	for(it=Messages.begin();it!=Messages.end();it++){
		if(*it.sender==fPerson || *it.receiver==fPerson)
			fResult.push_back();
	}
	return fResult;
}
