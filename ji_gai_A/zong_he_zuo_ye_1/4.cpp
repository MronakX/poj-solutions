/*
郭大卫
1900012995
01背包（浮点数）
19.12.11
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
//重量为浮点数，不能作为下标，无法dp，正常dfs
int n;
double m;
double v[1000] = {}, w[1000] = {};
double ans = 0;
void dfs(int num, double weight, double value)//num为物品编号，weight为当前重量。value为当前价值
{
	if(weight > m)//超重
		return;
	if(num > n-1)//选到最后一件物品，比较最大值
	{
		ans = max(ans, value);
		return;
	}
	dfs(num + 1, weight + w[num], value + v[num]);//取num号
	dfs(num + 1, weight, value);//不取num号
}
int main()
{
	//int dp[100][100] = {};
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> w[i] >> v[i];
	}
	dfs(0, 0, 0);
	cout << fixed << setprecision(5) << ans << endl;
	return 0;
}