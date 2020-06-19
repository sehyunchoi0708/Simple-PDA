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
        vector <Contacts> list; // Contacts ����Ʈ 
        vector <string> memos; //  �޸� ����Ʈ

        while (true)
        {

            int menu; int choice_menu_1; string choice2;
            cout << "=======================================================================================" << endl;
            cout << "������ PDA ����� �����մϴ�." << endl;
            cout << "���ϴ� ��ɿ� �ش��ϴ� ��ȣ�� �Է��ϼ���(1:�ּҷ�,2:�޸�,3:������ �ð�,4:�˶��ð�,5:�����,0:����)>>";
            cin >> menu;
            if (menu == 1) //�޴��� 1�̸�
            { //�ּҷ� ����� ��
                cout << "�ּҷ� ����(1:������ ���/2:������ �Է�/3:������ ����)>>";
                cin >> choice_menu_1; // ��� �Է�
                if (choice_menu_1 == 1) //��� ���
                {
                    for (int i = 0;i < list.size();i++)
                    {
                        cout << i + 1 << "��° ����ó" << endl;
                        list[i].showContacts();
                    } //vector�� �� ����� ��ȸ�ϸ鼭 �� ����� Contact��ü�� ����� ����ϴ� �Լ��� ȣ��
                }
                else if (choice_menu_1 == 2)
                { // �Է� ���
                    Contacts tmp; //Contact��ü ����
                    tmp.setContacts(); //�� ����� ����
                    list.push_back(tmp); // vector���ٰ� �Ҵ�
                }
                else if (choice_menu_1 == 3) // ������ ����
                {
                    int num; // ���° �ּҷ��� �����ϰ� ������ ��� ����
                    cout << "���° �ּҷ��� �����ϰ� �����Ű̴ϱ�?>>";
                    cin >> num;
                    list[num-1].setContacts(); // �� �ش��ϴ� Contacts ��ü���� ������ ����
                }
                else
                    cout << "�߸��� ��ȣ�� �Է��ϼ̽��ϴ�." << endl; //���� �߻��Ҷ� �ڵ�
                    


            }
            else if (menu == 2)
            {
                cout << "�޸��� ����Դϴ�. ������� �ִ� �޸��� ����� Ȯ���ϰڽ��ϱ�?(yes/no)";
                cin >> choice2; //�޸����� Ȯ������ ���ϴ� ����
                if (choice2 == "yes") //yes�̸�
                {
                    for (int i = 0;i < memos.size();i++) //vector�� �� ����� ��ȸ�ϸ鼭 ��ҵ鿡 ���� �޸� ����� ��ȣ ���� ���
                    {
                        cout << i + 1 << "��° �޸�" << endl; //���� ���
                        cout << memos[i] << endl; // �޸� �ּ� ���(����)
                    }
                    cout << "�� ��° �޸� �����Ͻ� �̴ϱ�(�߰��� ���Ѵٸ� ����ʽÿ�:0)>>?";
                    int memo_num; //���° �޸� �������� �Է�
                    cin >> memo_num; //�Է�

                    if (memo_num == 0) { // 0�̸� �޸� �߰���
                        string title;
                        cout << "���� �Է�:";
                        cin >> title;//������ �Է�
                        title = "C:\\Users\\user\\source\\repos\\" + title + ".txt"; //���� �ּҸ� ����
                        memos.push_back(title);// �� ����� ���ҿ� ���� �ּҸ� ����
                        ofstream fout(title); // ���� ���� 
                        if (!fout) {
                            cout << "���� ���� ����!" << endl;
                            return 0;
                        } //���� ���Ⱑ ������ ���� �����ϴ� ����
                        while (true)
                        {
                            cout << "�Է��� ����:(�������� exit Ŭ��>>"; // �Է��� ���� ����
                            string contents;
                            cin >> contents; // �Է��� ���� ����
                            if (contents == "exit") //exit�̸� ����
                                break;
                            fout << contents << endl; // ���Ͽ��ٰ� �Է��� ���� ����
                        }
                        fout.close(); //��ü �ݱ�
                    }
                    else
                    { //Ư�� �޸��� ���� ����

                        string title = memos[memo_num - 1]; // vector�� ���(Ư�� �ؽ�Ʈ ������ �ּ�) �����ؼ� ���� ���� 
                        cout << "��� ����(���뺸��:1/���� ����:2)>>"; // ��� ����
                        int mode;
                        cin >> mode;
                        if (mode == 1) { //1�� ����̸�(����)
                            ifstream fin(title); //�Է� ���� ���
                            if (!fin) {
                                cout << "���� ���� ����!" << endl;
                                return 0;
                            }//����
                            string line;
                            while (getline(fin, line)) {
                                cout << line << endl;
                            }//���پ� �޾ƿͼ� ���
                            fin.close(); //���� ��ü �ݱ�

                        }
                        else
                        { //������ �����Ұ��̸�
                            ofstream fout(title, ios::app); //�����ٰ� ������ �߰�
                            if (!fout) {
                                cout << "���� ���� ����!" << endl;
                                return 0;
                            } //������ ��Ÿ����
                            cout << "�߰��� ���� �Է�>>";
                            string contents;
                            cin >> contents; //�߰��� ���� �Է�
                            fout << contents << endl; //���Ͽ��ٰ� ������
                            fout.close(); //���� ��ü �ݱ�
                        }
                    }


                }
                else
                    cout << "�ٽ� �õ����ֽʽÿ�" << endl;
                
            }
            else if (menu == 3) //������ ��� 
            {
                Digital_Clock dgt;
                dgt.run_clock(); // ������ �ð� ����
            }
            else if (menu == 4)
            { //�˶����
                Digital_Clock dgt;
                dgt.run_alarm(); //�˶� ��� ����
            }
            else if (menu == 5) //���� ���
            {
                Calculator ct;
                ct.run(); //������ ����
            }
            else if (menu == 0)
            {
                break;
            }//���� ��ư
            else
                cout << "�ٽ� �ѹ� �Է����ֽñ� �ٶ��ϴ�."; //����
        } 
    }