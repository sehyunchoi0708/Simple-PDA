#include <string>
#include<iostream>
using namespace std;
#include "Calculator.h"

void Calculator::run() {
	while (true) {
		cout << "===============================================" << endl;
		cout << "� ������ �ϰ� ��������?(����/�E��/����/������) ��������:exit>>";
		cin >> mode; // ���� ��� ���ϱ�

		if (mode == "����") //add�Լ� ȣ��
		{
			add();
		}
		else if (mode == "����")//sub �Լ� ȣ��
		{
			sub();
		}
		else if (mode == "����")//mul �Լ� ȣ��
		{
			mul();
		}
		else if (mode == "������") //div �Լ� ȣ��
		{
			div();
		}

		else if (mode == "exit") // exit�� ������ ������
		{
			break;
		}
	}
}

void Calculator:: add() {
	cout << "���� ������ �ϰڽ��ϴ�" << endl;
	cout << "num1,num2�� ���ʴ�� �Է����ּ���" << endl;
	cin >> num1 >> num2; //�ǿ����� �Է�

	int result = 0; op = "+";
	result = num1 + num2; //���� ���� ����

	cout << num1 << op << num2 << "=" << result << endl;
}//���

void Calculator::sub() {
	cout << "���� ������ �ϰڽ��ϴ�" << endl;
	cout << "num1,num2�� ���ʴ�� �Է����ּ���" << endl;
	cin >> num1 >> num2; //�ǿ����� �Է�

	int result = 0;op = "-";
	result = num1 - num2; // ���� ���� ����

	cout << num1 << op << num2 << "=" << result << endl;
} // ���

void Calculator::mul() {
	cout << "���� ������ �ϰڽ��ϴ�" << endl;
	cout << "num1,num2�� ���ʴ�� �Է����ּ���" << endl;
	cin >> num1 >> num2; //�ǿ����� �Է�

	int result = 0; op = "*";
	result = num1 * num2;//���� ���� ����

	cout << num1 << op << num2 << "=" << result << endl;
}// ���

void Calculator::div() {
	cout << "������ ������ �ϰڽ��ϴ�" << endl;
	cout << "num1,num2�� ���ʴ�� �Է����ּ���" << endl;
	cin >> num1 >> num2; //�ǿ����� �Է�

	double result = 0.0; op = "/";
	result = num1*1.0 / num2; //������ ���� ����(Ÿ�� ĳ����)

	cout << num1 << op << num2 << "=" << result << endl;
} // ���
