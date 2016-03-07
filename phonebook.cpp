#include<phonebook.h>
#include<iostream>
#include<algorithm>


//파일의 내용을 읽어서 전화번호부에 추가
void Phonebook::readFile(const string& fileName){
	ifstream fin(fileName.c_str());
	Person per;
	while(fin.is_open()){
		fin>>per;
		people.push_back(per);
	}
}

//전화번호부를 파일에 저장
void Phonebook::saveFile(const string& fileName){
	ofstream fout(fileName.c_str());
	vector<Person>::iterator it;
	for(it=people.begin();it!=people.end();it++) fout<<*it;
}

//이름 순으로 정렬
void Phonebook::sorting(){
	sort(people.begin(),people.end());
}

//Person class를 전화번호부에 추가 후 정렬
void Phonebook::addPerson(const Person& per){
	people.push_back(per);
	sorting();
}

//people에 들어 있는 Person을 제거
void Phonebook::removePerson(const Person& per){
	vector<Person>::iterator it;
	int i=0;
	for(it=people.begin();it!=people.end();it++){
		if(strcmp(*it.name,per.name)==strcmp(*it.phone,per.phone)==strcmp(*it.memo,per.memo)==0) break;
		i++;
	}
	people.erase(people.begin()+i);
}

//전화번호부 내의 사람 수
int peopleOfPhoneBook(){
	return people.size();
}

//전화번호부 내의 모든 사람 출력
void showPhoneBook(){
	vector<Person>::iterator it;
	for(it=people.begin();it!=people.end();it++){
		cout<<*it;
		/*cout<<"Name : "<<*it.name<<endl;
		cout<<"Phone : "<<*it.phone<<endl;
		cout<<"Memo : "<<*it.memo<<"\n"<<endl;*/
	}
}

//이름을 통해 사람 검색
Person findName(const string& fName){
	vector<Person>::iterator it;
	PhoneBook sameName;
	int i=1;
	for(it=people.begin();it!=people.end();it++){
		if(*it.name==fName){
			sameName.push_back(*it);
			i++
		}
	}
	if(sameName.size()==1) return sameName[1];			//해당 이름을 가진 사람이 1사람만 존재할 경우
	else if(sameName.size()==0) return Person("None","None","None");			//해당 이름을 가진 사람이 존재하지 않을 경우
	else{
		cout<<"Choose the person's number who you are looking for"
		for(int j=1;j<=i;j++){
			cout<<j<<"."<<endl;
			cout<<sameName[j];
		}
		int k;
		cin>>k;
		return sameName[k];			//이름이 같은 사람이 여럿 존재할 경우
	}

}

//전화번호를 통해 사람 검색
Person findPhone(const string& fPhone){
	vector<Person>::iterator it;
	for(it=people.begin();it!=people.end();it++){
		if (*it.phone==fPhone) break;			//해당 전화번호가 존재할 경우
		else if(it==people.end()) return Person("None","None","None");			//해당 전화번호가 존재하지 않을 경우
	}
	return *it;
}
