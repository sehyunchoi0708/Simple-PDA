#ifndef DIGITAL_CLOCK
#define DIGITAL_CLOCK

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

class Digital_Clock
{
    int sec_prev=0; // 디지털 시계 내부 previous 초
    int dig_sec, dig_min, dig_hour = 0; // 디지털 내부의 시간,분,초
    int input_sec, input_min, input_hour = 0; //사용자 입력 시간,분,초
    string Am_Pm=""; //디지털 내부의 AM/PM 시간
    string input_Am_Pm=""; // 사용자 입력 AM/PM 시간

public:
    void run_clock(); // 디지털 시계만 보여주는 기능(인터페이스)
    void run_alarm(); // 디지털 시계와 시간이 되면 알람을 울리는 기능(인터페이스)
};

#endif 