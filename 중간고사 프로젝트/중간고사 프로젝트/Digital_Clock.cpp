#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
#include "Digital_Clock.h"

void Digital_Clock::run_clock(){
    while (true)
    {

        //storing total seconds
        time_t total_seconds = time(0); // 초단위의 구조체 타입의 시간 반환

        //getting values of seconds, minutes and hours
        struct tm* ct = localtime(&total_seconds); // 그 타입의 포인터 선언 및 할당

        dig_sec = ct->tm_sec;
        dig_min = ct->tm_min;
        dig_hour = ct->tm_hour;
        // 각 구조체의 멤버를 접근

        //converting it into 12 hour format
        if (dig_hour>= 12)
             Am_Pm= "PM";
        else
            Am_Pm = "AM";
        dig_hour = dig_hour > 12 ? dig_hour - 12 : dig_hour;

        // 시간이 12시가 넘으면 PM으로 설정하고 아니면 AM으로 설정함 또한 0~12까지이 디지털에서 출력할 것임

        //printing the result
        if (dig_sec == sec_prev + 1 || (sec_prev == 59 && dig_sec == 0)) // 1초 단위로
        {
            system("CLS"); //화면 업데이트
            cout << (dig_hour < 10 ? "0" : "") << dig_hour << ":" << (dig_min < 10 ? "0" : "") << dig_min << ":" 
                << (dig_sec < 10 ? "0" : "") << dig_sec << " " << Am_Pm << endl; //10보다 크면 0을 더해서 출력
        }

        sec_prev = dig_sec;//이전 시간을 지금 시간으로 설정->그래야 시간을 업데이트 해서 계속 흘러가게 할 수 있음

    }
}

void Digital_Clock::run_alarm() {
    cout << "Input the Hours you want to set(1~12)>>";
    cin >> input_hour; // 시간 설정

    cout << "Input the Minutes you want to set(1~60)>>";
    cin >> input_min;//분 설정

    cout << "Input the seconds you want to set(1~60)>>";
    cin >> input_sec;//초 설정

    cout << "Input Am or Pm>>";
    cin >> input_Am_Pm; //AM PM 설정

    while (true) {
        //storing total seconds
        time_t total_seconds = time(0); //마찬가지로 초단위의 시간 반환

        //getting values of seconds, minutes and hours
        struct tm* ct = localtime(&total_seconds); // 참조하는 포인터 선언 및 할당

        dig_sec = ct->tm_sec;
        dig_min = ct->tm_min;
        dig_hour = ct->tm_hour;
        //각 시간 멤버 제어

        //converting it into 12 hour format
        if (dig_hour >= 12) {
            Am_Pm = "PM";
            dig_hour -= 12;
        }
        else
            Am_Pm = "AM";
        // 12시를 기준으로 AMPM 설정하고 0~12까지 기준으로 알람과 디지털 시계를 구현할 것이기 때문에 -12를 함

        //printing the result
        if (dig_sec == sec_prev + 1 || (sec_prev == 59 && dig_sec == 0))
        {
            system("CLS"); // 1초단위로 출력 내용을 업데이트 함
            cout << (dig_hour < 10 ? "0" : "") << dig_hour << ":" << (dig_min < 10 ? "0" : "") << dig_min << ":"
                << (dig_sec < 10 ? "0" : "") << dig_sec << " " << Am_Pm << endl;
        }
        //10보다 크면 0을 덧붙여서 출력

        if ((dig_hour == input_hour) && (dig_min == input_min) && (dig_sec == input_sec))
        { // 디지털 시간과 알람에서 설정한 시간의 각 멤버를 비교
            system("CLS"); // 화면 업데이트
            cout << "Wake up man!" << endl; // 알람이 울리는 메세지 출력
            break;
        }

        sec_prev = dig_sec; //이전시간을 현재시간으로 맞추기
    }
}