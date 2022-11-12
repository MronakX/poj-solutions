/*
郭大卫
1900012995
1100 金银岛
19.12.11
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int k;
	cin >> k;
	for(int p=0; p<k; p++)
	{
		int w;
		int s;
		int n[20010] = {}, v[20010] = {};
		double single[10010] = {};//单价
		cin >> w >> s;
		for(int j=1; j<=s; j++)
		{
			cin >> n[j] >> v[j];
		}
		for(int j=1; j<=s; j++)
		{
			single[j] = double(v[j])/double(n[j]);//求出单价
		}
		for(int i=1; i<=s; i++)//冒泡排序，后续方便
		{
			for(int j=1; j<=s-i; j++)
			{
				if(single[j] < single[j+1])
				{
					swap(single[j], single[j+1]);
					swap(n[j], n[j+1]);
					swap(v[j], v[j+1]);
				}
			}
		}
		double ans = 0;
		int rest = w;//剩余容量
		for(int i=1; i<=s; i++)//贪心法，优先拿单价高的
		{
			if(n[i] >= rest)//拿不全，就装满剩余容量，退出循环
			{
				ans += rest * single[i];
				break;
			}
			else
			{
				rest -= n[i];
				ans += v[i]; 
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	system("PAUSE");
	return 0;
}