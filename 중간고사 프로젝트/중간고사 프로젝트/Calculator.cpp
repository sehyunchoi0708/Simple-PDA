#include <string>
#include<iostream>
using namespace std;
#include "Calculator.h"

void Calculator::run() {
	while (true) {
		cout << "===============================================" << endl;
		cout << "어떤 연산을 하고 싶은가요?(덧셈/뺼셈/곱셈/나눗셈) 나가려면:exit>>";
		cin >> mode; // 연산 모드 정하기

		if (mode == "덧셈") //add함수 호출
		{
			add();
		}
		else if (mode == "뺄셈")//sub 함수 호출
		{
			sub();
		}
		else if (mode == "곱셈")//mul 함수 호출
		{
			mul();
		}
		else if (mode == "나눗셈") //div 함수 호출
		{
			div();
		}

		else if (mode == "exit") // exit을 누르면 나가기
		{
			break;
		}
	}
}

void Calculator:: add() {
	cout << "덧셈 연산을 하겠습니다" << endl;
	cout << "num1,num2를 차례대로 입력해주세요" << endl;
	cin >> num1 >> num2; //피연산자 입력

	int result = 0; op = "+";
	result = num1 + num2; //덧셈 연산 수행

	cout << num1 << op << num2 << "=" << result << endl;
}//출력

void Calculator::sub() {
	cout << "뺄셈 연산을 하겠습니다" << endl;
	cout << "num1,num2를 차례대로 입력해주세요" << endl;
	cin >> num1 >> num2; //피연산자 입력

	int result = 0;op = "-";
	result = num1 - num2; // 뺄셈 연산 수행

	cout << num1 << op << num2 << "=" << result << endl;
} // 출력

void Calculator::mul() {
	cout << "곱셈 연산을 하겠습니다" << endl;
	cout << "num1,num2를 차례대로 입력해주세요" << endl;
	cin >> num1 >> num2; //피연산자 입력

	int result = 0; op = "*";
	result = num1 * num2;//곱셈 연산 수행

	cout << num1 << op << num2 << "=" << result << endl;
}// 출력

void Calculator::div() {
	cout << "나눗셈 연산을 하겠습니다" << endl;
	cout << "num1,num2를 차례대로 입력해주세요" << endl;
	cin >> num1 >> num2; //피연산자 입력

	double result = 0.0; op = "/";
	result = num1*1.0 / num2; //나눗셈 연산 수행(타입 캐스팅)

	cout << num1 << op << num2 << "=" << result << endl;
} // 출력
