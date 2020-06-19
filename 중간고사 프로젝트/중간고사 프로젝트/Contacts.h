#ifndef CONTACTS
#define CONTACTS
#include <iostream>
#include <string>
using namespace std;
class Contacts
{
private:
	int id; //연락처를 구별할 id
	string name; // 연락처 이름
	string tel; // 연락처
	string memo; // 특이사항
public:
	Contacts() {} //defualt 생성자
	Contacts(int id, string name, string tel="", string memo=""); //생성자
	void setContacts(); // 연락처에 대한 설정자
	void showContacts(); //관련 정보를 모두 출력하는 함수

};




#endif
