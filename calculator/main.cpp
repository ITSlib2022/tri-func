/*************************************************

Function:������

Description:���ø������ܺ�����ʵ�����Ǻ����뷴���Ǻ����������Ĺ���

************************************************ */
#include<iostream>
#include"tab.h"
#include"Trigonometric.h"
#include"arctan.h"
#include"menu.h"
#include"arcsin.h"
using namespace std;
int main()
{
	cout.precision(10);
	int key_select = 100;//����ѡ���
	while (true)
	{
		showMenu();
		cin >> key_select;
		switch (key_select)
		{
		case 1:
		{
			int key_unit;//��λѡ���־
			cout << "��ѡ����ϣ��ʹ�õĵ�λ��1.�Ƕ�     2.����" << endl;
			cin >> key_unit;
			double beta;
			if (key_unit == 1)
			{
				cout << "������Ƕ�beta" << endl;
				cin >> beta;
				//���������Ҽ��㺯������Ϊ����ֵ������ֵ������ֵ�������ýṹ��������ܷ���ֵ
				struct Result r = Trigonometric(beta);
				cout << "sin(beta)=" << r.sine << endl;
				cout << "cosin(beta)=" << std::fixed << r.cosine << endl;
			}
			else if (key_unit == 2)
			{
				cout << "�����뻡��ֵbeta" << endl;
				cin >> beta;
				//��ѡ��ĵ�λΪ���ȣ����Ƚ���ת��Ϊ�Ƕ�
				beta = beta * 180 / pi;
				struct Result r = Trigonometric(beta);
				cout << "sin(beta)=" << r.sine << endl;
				cout << "cosin(beta)=" << std::fixed << r.cosine << endl;
			}
			else
				cout << "��ѡ����ȷ�ĵ�λ" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			int key_unit;
			cout << "��ѡ����ϣ��ʹ�õĵ�λ��1.�Ƕ�     2.����" << endl;
			cin >> key_unit;
			if (key_unit == 1 || key_unit == 2)
			{
				double numy;
				cout << "����������ֵ��" << endl;
				cin >> numy;
				double angle = arctan(numy);
				if (key_unit == 1)
					cout << "��Ӧ�Ƕ�Ϊ��" << angle << endl;
				else
				{
					angle = angle / 180 * pi;
					cout << "��Ӧ����Ϊ��" << angle << endl;
				}
			}
			else
				cout << "��ѡ����ȷ�ĵ�λ" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			int key_unit;
			cout << "��ѡ����ϣ��ʹ�õĵ�λ��1.�Ƕ�     2.����" << endl;
			cin >> key_unit;
			if (key_unit == 1 || key_unit == 2)
			{
				double numy;
				cout << "����������ֵ��" << endl;
				cin >> numy;
				double angle = arcsin(numy);
				if (key_unit == 1)
					cout << "��Ӧ�Ƕ�Ϊ��" << angle << endl;
				else
				{
					angle = angle / 180 * pi;
					cout << "��Ӧ����Ϊ��" << angle << endl;
				}
			}
			else
				cout << "��ѡ����ȷ�ĵ�λ" << endl;
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			system("pause");
			return 0;
		}
		}
	}
}