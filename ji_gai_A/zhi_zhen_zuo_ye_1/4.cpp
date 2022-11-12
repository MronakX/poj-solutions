/*
郭大卫
1900012995
字符串中最长的连续出现的字符
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
	int n;
	cin >> n;
	char str[220] = {};
	for(int i=0;i<n;i++)
	{
		cin >> str;
		int ans = 0;
		char ch = str[0];
		int len = strlen(str);
		char *p = str;//指向开头
		int cnt = 0;//目前长度
		while(*p != '\000')//字符串未停止
		{
			if(*p == *(p+1))
			{
				cnt++;
				p++;
			}
			else//当某位与下一位不同，停止计数，取最长长度
			{
				if(ans < cnt)//不要小于等于
				{
					ans = cnt;
					ch = *(p-1);
				}
				cnt = 1;
				p++;
			}	
		}
		cout << ch << " " << ans << endl;
	}
	
	system("PAUSE");
	return 0;
} 