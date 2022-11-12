	/*
	郭大卫
	1900012995
	二维数组中的最大数
	19.12.12
	*/
	#include <iostream>
	#include <iomanip>
	#include <cmath>
	#include <cstring>
	using namespace std;
	int main()
	{
		int a[4][3] = {};
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin >> a[i][j];
			}
		}
		int *p;
		p = *a;//指向二维数组开头，降为一维数组
		int maxnum = -10000, maxlen = -10000, addr = 0;//考虑负数情况，初值赋负数
		for(int i=0;i<12;i++)
		{
			if(maxnum < *(p+i))
			{
				maxnum = *(p+i);
				maxlen = i+1;
				addr = 2000 + 4*i;
			}
		}
		cout << maxnum << " " << maxlen << endl << addr << endl;
		system("PAUSE");
		return 0;
	}