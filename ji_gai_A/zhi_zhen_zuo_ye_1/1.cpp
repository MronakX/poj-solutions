/*
郭大卫
1900012995
找特定单词
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
	char str[110];
	char ch1[2] = {'e'};//用于strstr函数
	char ch2[2] = {'a'};
	int flag = 0;//flag用于标记是否是第一个字符串
	while(cin >> str)
	{
		if((strstr(str,ch1) != NULL || strstr(str,ch2)) != NULL && flag)
		{
			cout << " " << str ;
		}
		if((strstr(str,ch1)!= NULL || strstr(str,ch2)) != NULL && !flag)
		{
			cout << str ;
			flag = 1;
		}
		memset(str,0,sizeof(str));
	}
	return 0;
} 