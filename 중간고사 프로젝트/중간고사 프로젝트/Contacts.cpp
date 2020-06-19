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
} //생성자에서 각 멤버에게 데이터 할당

void Contacts::setContacts() {
	while (true) {

		int menu; string choice; //menu를 통해 수정할 부분 설정 // choice를 통해서 수정을 계속할지 말지 결정
		cout << "======================================================" << endl;
		cout << "수정(입력)할 부분을 선택하세요(Id:1/이름:2/전화번호:3/특이사항:4/종료:0)>>";
		cin >> menu; // menu 입력

		if (menu == 1)
		{
			cout << "Id 를 입력하세요>>";
			cin >> this->id;
		} // Id 설정

		else if (menu == 2) {
			cout << "이름을 입력하세요>>";
			cin >> this->name;
		} // 이름 설정
		else if (menu == 3) {
			cout << "전화번호를 입력하세요>>";
			cin >> this->tel;
		} // 전화번호 설정
		else if (menu == 4) {
			cout << "특이사항을 입력하세요>>";
			cin >> this->memo;
		} // 특이사항 설정
		else if (menu == 0) {
			cout << "수정을 마칩니다" << endl;
			break;
		}// 종료
		else
			cout << "잘못 입력하셨습니다" << endl; //에러

		cout << "수정이 완료되었습니다." << endl;
		cout << "계속 진행하시겠습니까?(yes/no)"; // 계속할지 말지 여부를 물어봄
		cin >> choice;
		if (choice == "no")
			break; // no이면 빠져나간다
		else if (choice == "yes")
			continue; //yes면 계속 while문 선회
		else {
			cout << "잘못 입력 하였습니다" << endl;
			break; //오류
		}

	}
}

void Contacts::showContacts() { // Contacts 객체의 각 멤버를 출력
	cout << "=================================================" << endl;
	cout << "ID: " << this->id << endl;
	cout << "이름: " << this->name << endl;
	cout << "전화번호: " << this->tel << endl;
	cout << "특이사항: " << this->memo << endl;
	cout << "=================================================" << endl;
}




