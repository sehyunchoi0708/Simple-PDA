#ifndef CALCULATOR_
#define CALCULATOR_
#include <string>
#include<iostream>
using namespace std;


class Calculator {
	string op = ""; //연산자
	int num1, num2 = 0; // 피연산자
	string mode = ""; // 무슨 연산을 수행할지에 대한 모드

public:
	void run(); //계산기 수행
	void add();//덧셈
	void sub();//뺄셈
	void mul();//곱셈
	void div();//나눗셈
};


#endif
