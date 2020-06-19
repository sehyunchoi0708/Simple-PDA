#ifndef DIGITAL_CLOCK
#define DIGITAL_CLOCK

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

class Digital_Clock
{
    int sec_prev=0; // ������ �ð� ���� previous ��
    int dig_sec, dig_min, dig_hour = 0; // ������ ������ �ð�,��,��
    int input_sec, input_min, input_hour = 0; //����� �Է� �ð�,��,��
    string Am_Pm=""; //������ ������ AM/PM �ð�
    string input_Am_Pm=""; // ����� �Է� AM/PM �ð�

public:
    void run_clock(); // ������ �ð踸 �����ִ� ���(�������̽�)
    void run_alarm(); // ������ �ð�� �ð��� �Ǹ� �˶��� �︮�� ���(�������̽�)
};

#endif 