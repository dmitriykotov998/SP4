#include <iostream>
#include <sys/wait.h>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
        char buff[100]; // �����
        int Sot, SotSteal = 30; //���������� �������� � ���������� ������� ������ �������

        ifstream file; //���������� ��� ������ � ������
        ofstream file1;

        pid_t bear; //���������� ������������� ��������
        bear = fork(); //��������� �������
        //����������� ����
        for(;;) {
                file.open("honey.txt");// �������
                file >> buff; // ������� � ����� � �������� � �����
                file.close(); // �������
                Sot=atoi(buff); // �������� � int � ���������� �������� ������ � Sot
                // ���� ������� ������� � �������� Sot ������ ��� ����� 30
                if(!bear && Sot>=30) {
                        Sot-=SotSteal; // �������� �� ����� ���������� �������� ������� ������ �������

                        cout << "ID Bear: " << getpid() << endl; // ������ id ��������
                        cout << "Bear steal sot: " << Sot << endl << endl; // ������ �������� ����� ���������
                        sprintf(buff, "%d", Sot); // �������� � ������

                        file1.open("honey.txt"); // �������
                        file1 << buff; // �������� � ������� � ����
                        file1.close(); // �������

                        sleep(4); // ���� 4 �������
                }
                
                if (Sot<30)
                {
                	cout << "Honey empty" << endl; 
                	return 0;
				}

                pid_t bee; // ������������� ��������
                bee = fork(); // �������� ������� �����
                wait(0); // � ��� ���� �������� �� ������� ������
                // ���� ������� �������
                if(!bee) {
                        cout << "ID Bee: " << getpid() << endl; // ������ id ��������
                        execl ("bee", "NULL" , NULL, NULL); // �������� ������ ���������
                        kill(getpid(), SIGKILL); // ���������� ����� �������
                }
        }
        return 0;
}


