#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include<iostream>
using namespace std;
#include "Contacts.h"

Contacts::Contacts(int id, string name, string tel, string  memo) {
	this->id = id;
	this->name = name;
	this->tel = tel;
	this->memo = memo;
} //�����ڿ��� �� ������� ������ �Ҵ�

void Contacts::setContacts() {
	while (true) {

		int menu; string choice; //menu�� ���� ������ �κ� ���� // choice�� ���ؼ� ������ ������� ���� ����
		cout << "======================================================" << endl;
		cout << "����(�Է�)�� �κ��� �����ϼ���(Id:1/�̸�:2/��ȭ��ȣ:3/Ư�̻���:4/����:0)>>";
		cin >> menu; // menu �Է�

		if (menu == 1)
		{
			cout << "Id �� �Է��ϼ���>>";
			cin >> this->id;
		} // Id ����

		else if (menu == 2) {
			cout << "�̸��� �Է��ϼ���>>";
			cin >> this->name;
		} // �̸� ����
		else if (menu == 3) {
			cout << "��ȭ��ȣ�� �Է��ϼ���>>";
			cin >> this->tel;
		} // ��ȭ��ȣ ����
		else if (menu == 4) {
			cout << "Ư�̻����� �Է��ϼ���>>";
			cin >> this->memo;
		} // Ư�̻��� ����
		else if (menu == 0) {
			cout << "������ ��Ĩ�ϴ�" << endl;
			break;
		}// ����
		else
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl; //����

		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
		cout << "��� �����Ͻðڽ��ϱ�?(yes/no)"; // ������� ���� ���θ� ���
		cin >> choice;
		if (choice == "no")
			break; // no�̸� ����������
		else if (choice == "yes")
			continue; //yes�� ��� while�� ��ȸ
		else {
			cout << "�߸� �Է� �Ͽ����ϴ�" << endl;
			break; //����
		}

	}
}

void Contacts::showContacts() { // Contacts ��ü�� �� ����� ���
	cout << "=================================================" << endl;
	cout << "ID: " << this->id << endl;
	cout << "�̸�: " << this->name << endl;
	cout << "��ȭ��ȣ: " << this->tel << endl;
	cout << "Ư�̻���: " << this->memo << endl;
	cout << "=================================================" << endl;
}




