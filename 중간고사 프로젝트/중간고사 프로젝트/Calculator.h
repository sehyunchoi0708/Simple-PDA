#ifndef CALCULATOR_
#define CALCULATOR_
#include <string>
#include<iostream>
using namespace std;


class Calculator {
	string op = ""; //������
	int num1, num2 = 0; // �ǿ�����
	string mode = ""; // ���� ������ ���������� ���� ���

public:
	void run(); //���� ����
	void add();//����
	void sub();//����
	void mul();//����
	void div();//������
};


#endif
