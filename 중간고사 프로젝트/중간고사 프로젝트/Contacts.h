#ifndef CONTACTS
#define CONTACTS
#include <iostream>
#include <string>
using namespace std;
class Contacts
{
private:
	int id; //����ó�� ������ id
	string name; // ����ó �̸�
	string tel; // ����ó
	string memo; // Ư�̻���
public:
	Contacts() {} //defualt ������
	Contacts(int id, string name, string tel="", string memo=""); //������
	void setContacts(); // ����ó�� ���� ������
	void showContacts(); //���� ������ ��� ����ϴ� �Լ�

};




#endif
