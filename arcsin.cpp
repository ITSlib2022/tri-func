/* ************************************************

Function:�����Ҽ��㺯��

Description:���ݹ�ʽ arcsin(x)=arctan(x/sqrt(1-x*x))������������ֵ��Ӧ�ĽǶ�

Input:����ֵ

Output:����ֵ��Ӧ�ĽǶ�

Return:����ֵ��Ӧ�ĽǶ�

************************************************ */

#include<iostream>
#include"tab.h"
#include"arctan.h"
#include"arcsin.h"
#include<math.h>
using namespace std;

double arcsin(double input_value_sin)
{
	if (input_value_sin > 1)
		cout << "����ֵ���������Һ���������" << endl;
	else if (input_value_sin == 1)
		input_value_sin = 999999999999;
	else
		input_value_sin = input_value_sin / sqrt(1 - input_value_sin * input_value_sin);
	double angle = arctan(input_value_sin);
	return angle;
}