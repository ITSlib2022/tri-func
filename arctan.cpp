/*************************************************

Function:�����м��㺯��

Description:����Cordic�㷨������������ֵ��Ӧ�ĽǶ�

Input:����ֵ

Output:����ֵ��Ӧ�ĽǶ�

Return:����ֵ��Ӧ�ĽǶ�

Cordic�㷨����������ֵ���Կ�������v(1,input_value_tan)��Ӧ������ֵ��
            ������v��תһ������������ת��ɺ�v'�������Ϊ0
			��������ת�Ƕ�֮�ͼ�Ϊ��������ֵ��Ӧ�ĽǶ�
*************************************************/

#include<iostream>
#include"tab.h"
#include"arctan.h"
using namespace std;

double arctan(double input_value_tan)
{
	double y = input_value_tan;   //��ʼ����v��������
	double x = 1;                 //��ʼ����v�ĺ�����
	double x_new, y_new;          //��ת������v'������
	double poweroftwo = 1;        //1/2��n�η���nΪ��ת����
	double anglesum = 0;          //

	for (int i = 0; i < sizeof(angles) / sizeof(double); i++)
	{
		if (y > 0)
		{
			y_new = y - x * poweroftwo;
			x_new = x + y * poweroftwo;
			y = y_new;
			x = x_new;
			anglesum += angles[i];
			poweroftwo = poweroftwo / 2;
		}
		else if (y < 0)
		{
			y_new = y + x * poweroftwo;
			x_new = x - y * poweroftwo;
			y = y_new;
			x = x_new;
			anglesum -= angles[i];
			poweroftwo = poweroftwo / 2;
		}
		else
			break;
	}
	return anglesum;
}