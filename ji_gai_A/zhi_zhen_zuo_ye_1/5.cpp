/*
郭大卫
1900012995
自己动手丰衣足食
19.12.04
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char str[100];
	while(1)
	{
		cin >> str;
		int len = strlen(str);
		double num = 0;
		if(str[0] == 'q') 
			break;	
		int dotpos = 0;//小数点位置
		int letterpos = len;//字符位置
		char *p = str;//指向开头
		for(int i = 0; i<len; i++)
		{
			if(*(p+i) == '-' || *(p+i) == '+')//第一位，不管
			{
				continue;
			}
			if((*(p+i) <'0' || *(p+i) >'9') && *(p+i) !='.')//找到字符，停止循环，记录位置
			{
				letterpos = i;
				break;
			}
			if(*(p+i) != '.')//字符换转化为数字
			{
				num = 10*num + (*(p+i)-'0');
			}	
			if(*(p+i) == '.')//找到小数点，记录位置
			{
				dotpos = i;
			}
		}
		if(dotpos)
		{
			for(int i=dotpos+1; i<letterpos; i++)//加入小数点
			{
				num /= 10;
			}
		}
		//cout << num << endl;
		if(letterpos == len)//没有乘方符号，输出，判断负号
		{
			if(str[0] == '-')
				cout << fixed << setprecision(6) << "-" << num << endl;
			else
				cout << fixed << setprecision(6) << num << endl;
		}
		if(letterpos != len)
		{
			double power = 0;
			for(int j = letterpos + 1; j<len; j++)//求出乘方数
			{
				if(*(p+j) == '+')
				{
					continue;
				}
				if(*(p+j) != '-')
				{
					power = 10*power + (*(p+j) - '0');
				}
			}
			if(*(p+letterpos+1) == '-')
			{
				power = -power;
			}
			num = num * pow(10, power);
			if(str[0] == '-')
				cout << fixed << setprecision(6) << "-" << num << endl;
			else
				cout << fixed << setprecision(6) << num << endl;
		}
	}

	system("PAUSE");
	return 0;
}