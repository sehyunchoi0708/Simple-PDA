#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
#include "Digital_Clock.h"

void Digital_Clock::run_clock(){
    while (true)
    {

        //storing total seconds
        time_t total_seconds = time(0); // �ʴ����� ����ü Ÿ���� �ð� ��ȯ

        //getting values of seconds, minutes and hours
        struct tm* ct = localtime(&total_seconds); // �� Ÿ���� ������ ���� �� �Ҵ�

        dig_sec = ct->tm_sec;
        dig_min = ct->tm_min;
        dig_hour = ct->tm_hour;
        // �� ����ü�� ����� ����

        //converting it into 12 hour format
        if (dig_hour>= 12)
             Am_Pm= "PM";
        else
            Am_Pm = "AM";
        dig_hour = dig_hour > 12 ? dig_hour - 12 : dig_hour;

        // �ð��� 12�ð� ������ PM���� �����ϰ� �ƴϸ� AM���� ������ ���� 0~12������ �����п��� ����� ����

        //printing the result
        if (dig_sec == sec_prev + 1 || (sec_prev == 59 && dig_sec == 0)) // 1�� ������
        {
            system("CLS"); //ȭ�� ������Ʈ
            cout << (dig_hour < 10 ? "0" : "") << dig_hour << ":" << (dig_min < 10 ? "0" : "") << dig_min << ":" 
                << (dig_sec < 10 ? "0" : "") << dig_sec << " " << Am_Pm << endl; //10���� ũ�� 0�� ���ؼ� ���
        }

        sec_prev = dig_sec;//���� �ð��� ���� �ð����� ����->�׷��� �ð��� ������Ʈ �ؼ� ��� �귯���� �� �� ����

    }
}

void Digital_Clock::run_alarm() {
    cout << "Input the Hours you want to set(1~12)>>";
    cin >> input_hour; // �ð� ����

    cout << "Input the Minutes you want to set(1~60)>>";
    cin >> input_min;//�� ����

    cout << "Input the seconds you want to set(1~60)>>";
    cin >> input_sec;//�� ����

    cout << "Input Am or Pm>>";
    cin >> input_Am_Pm; //AM PM ����

    while (true) {
        //storing total seconds
        time_t total_seconds = time(0); //���������� �ʴ����� �ð� ��ȯ

        //getting values of seconds, minutes and hours
        struct tm* ct = localtime(&total_seconds); // �����ϴ� ������ ���� �� �Ҵ�

        dig_sec = ct->tm_sec;
        dig_min = ct->tm_min;
        dig_hour = ct->tm_hour;
        //�� �ð� ��� ����

        //converting it into 12 hour format
        if (dig_hour >= 12) {
            Am_Pm = "PM";
            dig_hour -= 12;
        }
        else
            Am_Pm = "AM";
        // 12�ø� �������� AMPM �����ϰ� 0~12���� �������� �˶��� ������ �ð踦 ������ ���̱� ������ -12�� ��

        //printing the result
        if (dig_sec == sec_prev + 1 || (sec_prev == 59 && dig_sec == 0))
        {
            system("CLS"); // 1�ʴ����� ��� ������ ������Ʈ ��
            cout << (dig_hour < 10 ? "0" : "") << dig_hour << ":" << (dig_min < 10 ? "0" : "") << dig_min << ":"
                << (dig_sec < 10 ? "0" : "") << dig_sec << " " << Am_Pm << endl;
        }
        //10���� ũ�� 0�� ���ٿ��� ���

        if ((dig_hour == input_hour) && (dig_min == input_min) && (dig_sec == input_sec))
        { // ������ �ð��� �˶����� ������ �ð��� �� ����� ��
            system("CLS"); // ȭ�� ������Ʈ
            cout << "Wake up man!" << endl; // �˶��� �︮�� �޼��� ���
            break;
        }

        sec_prev = dig_sec; //�����ð��� ����ð����� ���߱�
    }
}