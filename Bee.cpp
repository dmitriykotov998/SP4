#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
	    char buff[100]; // �����
        int Sot, BeeHoney = 10; // ���������� �������� � ���������� � ������� ����� ���������� ��

        ifstream file; // ���������� ��� ������ � ������
        ofstream file1;

        file.open("honey.txt"); // �������
        file >> buff; // ������� � �������� � �����
        file.close(); // �������

        Sot = atoi(buff);// �������� � int � ���������� �������� ������ � Sot
        Sot += BeeHoney;// ����������� ��������� �������� �� ���������� ����������� ���
        sprintf(buff, "%d", Sot); // �������� � ������

        cout << "Honey: " << Sot << endl; // ������

        file1.open("honey.txt"); // �������
        file1 << buff; // �������� � ������� � ����
        file1.close();// �������

        sleep(1); // ���� 1 �������
}
