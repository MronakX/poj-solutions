/*
郭大卫
1900012995
整数删除若干数字后的最小数
19.12.05
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char str[101] = {};
	int n;
	cin >> str >> n;
	char *p = str;
	int len = strlen(str);
	int cnt = 0;//当前删除数量
	//贪心，每次从头循环遍历，删除最考前的较大数
	for(int i=0; i<len-cnt; i++)
	{
		if(*(p+i+1) < *(p+i))
		{
			for(int j=i; j<len-1; j++)//字符串前移1位
			{
				*(p+j) = *(p+j+1);
			}
			cnt++;
			i = -1;//归零
		}
		if(cnt == n)
		{
			break;
		}
	}
	int flag = 0;//判断首位是否是0
	for(int i=0; i<len-n; i++)
	{
		if(flag)
		{
			cout << *(p+i);
		}
		if(*(p+i) != '0' && !flag)
		{
			cout << *(p+i);
			flag = 1;
		}
	}
	if(!flag)//只剩0
	{
		cout << "0";
	}
	cout << endl;
	
	
	system("PAUSE");
	return 0;
}