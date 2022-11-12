	/*
	郭大卫
	1900012995
	循环移动
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
		int n, m;
		cin >> n >> m;
		int a[200] = {};
		for(int i=0;i<n;i++)
		{
			cin >> a[i];//输入字符串
		}
		int *p = a;//指向数组开头
		p = a+n;//指向末尾
		for(int i=n; i>=0; i--)
		{
			*(p + m) = *p;//后移m位
			p--;
		}
		p = a;
		for(int i=0; i<m; i++)
		{
			*p = *(p+n);//前m位填充
			p++;
		}
		p = a;//指向开头
		cout << *p++;
		for(int i=1; i<n; i++)//输出前n个数字
		{
			cout << " " << *p++;
		}
	system("PAUSE");
	return 0;
	} 