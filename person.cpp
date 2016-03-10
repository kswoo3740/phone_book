#include <person.h>
#include <iostream>

using namespace std;

//이름, 번호, 메모를 받아 대입하는
Person::Person(const string& newName, const string& newPhone, const string& newMemo){
	name = new string(newName);
	phone = new string(newPhone);
	memo = new string(newMemo);
}

//Person class를 받아 대입하는
Person::Person(const Person& newPerson){
	name = new string(*newPerson.name);
	phone = new string(*newPerson.phone);
	memo = new string(*newPerson.memo);
}

//Person class 변수 초기화
Person::~Person(){
	delete name;
	delete phone;
	delete memo;
}

//class 안에 저장된 변수들 출력
Person::ShowInfo(){
	cout<<"Name : "<<name<<endl;
	cout<<"Phonenumber : "<<phone<<endl;
	cout<<"Memo : "<<memo<<endl;
}

//이름만 설정
void Person::setName(const string& newName){
	delete name;
	name = new string(newName);
}

//전화번호만 설정
void Person::setPhone(const string& newPhone){
	delete phone;
	phone = new string(newPhone);
}

//메모만 설정
void Person::setMemo(const string& newMemo){
	delete memo;
	memo = new string(newMemo);
}

//파일에서 각각 변수 대입
ifstrema& Person::operator>>(ifstream& fin, Person& per){
	fin>>*per.name;
	fin>>*per.phone;
	fin>>*per.memo;
	return fin;
}

//파일에 각각 변수 저장
ofstream& Person::operator<<(ofstream& fout, const Person& per){
	fout<<*per.name<<"\n";
	fout<<*per.phone<<"\n";
	fout<<*per.memo<<"\n";
	return fout;
}

//각각의 변수 출력
ostream& Person::operator<<(ostream& sout, const Person& per){
	sout<<"Name : "<<per.name<<endl;
	sout<<"Phonenumber : "<<per.phone<<endl;
	sout<<"Memo : "<<per.memo<<endl;
	return sout;
}

//class안의 변수 대입
Person& Person::operator=(const Person& per){
	delete this->name;
	delete this->phone;
	delete this->memo;
	this->name = new string(*per.name);
	this->phone = new string(*per.phone);
	this->memo  = new string(*per.memo);
	return *this;
}

//class간의 변수 비교
bool Person::operator==(const Person& per){
	return (*name == *per.name) & (*phone == *per.phone) & (*memo == *per.memo);
}

//sort를 위해 class안의 이름 혹은 번호를 통해 비교
bool Person::operator<(const Person& fPer,const Person& sPer){
	if(*fPer.name != *sPer.name) return *fPer.name < *sPer.name;
	if(*fPer.phone != *sPer.phone) return *fPer.phone < *sPer.phone;
	else return true;
}
