#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
#include "Digital_Clock.h"
#include "Calculator.h"
#include "Contacts.h"
#include <vector>
#include <fstream>
    int main() {
        vector <Contacts> list; // Contacts 리스트 
        vector <string> memos; //  메모 리스트

        while (true)
        {

            int menu; int choice_menu_1; string choice2;
            cout << "=======================================================================================" << endl;
            cout << "간단한 PDA 기능을 제공합니다." << endl;
            cout << "원하는 기능에 해당하는 번호를 입력하세요(1:주소록,2:메모,3:디지털 시계,4:알람시계,5:계산기능,0:종료)>>";
            cin >> menu;
            if (menu == 1) //메뉴가 1이면
            { //주소록 기능을 들어감
                cout << "주소록 관리(1:데이터 출력/2:데이터 입력/3:데이터 수정)>>";
                cin >> choice_menu_1; // 모드 입력
                if (choice_menu_1 == 1) //출력 기능
                {
                    for (int i = 0;i < list.size();i++)
                    {
                        cout << i + 1 << "번째 연락처" << endl;
                        list[i].showContacts();
                    } //vector의 각 멤버를 선회하면서 그 멤버의 Contact객체의 멤버를 출력하는 함수를 호출
                }
                else if (choice_menu_1 == 2)
                { // 입력 기능
                    Contacts tmp; //Contact객체 생성
                    tmp.setContacts(); //각 멤버들 설정
                    list.push_back(tmp); // vector에다가 할당
                }
                else if (choice_menu_1 == 3) // 데이터 수정
                {
                    int num; // 몇번째 주소록을 변경하고 싶은지 담는 변수
                    cout << "몇번째 주소록을 변경하고 싶으신겁니까?>>";
                    cin >> num;
                    list[num-1].setContacts(); // 그 해당하는 Contacts 객체에서 데이터 수정
                }
                else
                    cout << "잘못된 번호를 입력하셨습니다." << endl; //오류 발생할때 코드
                    


            }
            else if (menu == 2)
            {
                cout << "메모장 기능입니다. 만들어져 있는 메모장 목록을 확인하겠습니까?(yes/no)";
                cin >> choice2; //메모장을 확인할지 정하는 문구
                if (choice2 == "yes") //yes이면
                {
                    for (int i = 0;i < memos.size();i++) //vector의 각 멤버를 순회하면서 요소들에 대한 메모 제목과 번호 순서 출력
                    {
                        cout << i + 1 << "번째 메모" << endl; //순서 출력
                        cout << memos[i] << endl; // 메모 주소 출력(제목)
                    }
                    cout << "몇 번째 메모를 선택하실 겁니까(추가를 원한다면 만드십시오:0)>>?";
                    int memo_num; //몇번째 메모를 선택할지 입력
                    cin >> memo_num; //입력

                    if (memo_num == 0) { // 0이면 메모를 추가함
                        string title;
                        cout << "제목 입력:";
                        cin >> title;//제목을 입력
                        title = "C:\\Users\\user\\source\\repos\\" + title + ".txt"; //절대 주소를 생성
                        memos.push_back(title);// 각 멤버의 원소에 절대 주소를 대입
                        ofstream fout(title); // 파일 열기 
                        if (!fout) {
                            cout << "파일 열기 오류!" << endl;
                            return 0;
                        } //파일 열기가 오류가 나면 실행하는 구문
                        while (true)
                        {
                            cout << "입력할 내용:(나가려면 exit 클릭>>"; // 입력할 내용 대입
                            string contents;
                            cin >> contents; // 입력한 내용 저장
                            if (contents == "exit") //exit이면 나감
                                break;
                            fout << contents << endl; // 파일에다가 입력한 내용 저장
                        }
                        fout.close(); //객체 닫기
                    }
                    else
                    { //특정 메모의 내용 선택

                        string title = memos[memo_num - 1]; // vector의 멤버(특정 텍스트 파일의 주소) 선택해서 제목 대입 
                        cout << "기능 선택(내용보기:1/내용 수정:2)>>"; // 기능 선택
                        int mode;
                        cin >> mode;
                        if (mode == 1) { //1번 모드이면(보기)
                            ifstream fin(title); //입력 모드로 열어서
                            if (!fin) {
                                cout << "파일 열기 오류!" << endl;
                                return 0;
                            }//오류
                            string line;
                            while (getline(fin, line)) {
                                cout << line << endl;
                            }//한줄씩 받아와서 출력
                            fin.close(); //파일 객체 닫기

                        }
                        else
                        { //내용을 수정할것이면
                            ofstream fout(title, ios::app); //끝에다가 내용을 추가
                            if (!fout) {
                                cout << "파일 열기 오류!" << endl;
                                return 0;
                            } //오류가 나타날때
                            cout << "추가할 내용 입력>>";
                            string contents;
                            cin >> contents; //추가할 내용 입력
                            fout << contents << endl; //파일에다가 덧붙임
                            fout.close(); //파일 객체 닫기
                        }
                    }


                }
                else
                    cout << "다시 시도해주십시오" << endl;
                
            }
            else if (menu == 3) //디지털 기능 
            {
                Digital_Clock dgt;
                dgt.run_clock(); // 디지털 시계 동작
            }
            else if (menu == 4)
            { //알람기능
                Digital_Clock dgt;
                dgt.run_alarm(); //알람 기능 동작
            }
            else if (menu == 5) //계산기 기능
            {
                Calculator ct;
                ct.run(); //계산기기능 동작
            }
            else if (menu == 0)
            {
                break;
            }//종료 버튼
            else
                cout << "다시 한번 입력해주시기 바랍니다."; //오류
        } 
    }