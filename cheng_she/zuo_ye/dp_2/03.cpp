/*
郭大卫
1900012995
动规2 -- C:Charm Bracelet
20.05.20
0-1背包 一维滚动数组dp 注意清零，以及从右向左循环
*/

#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int w[4000] = {}, d[4000] = {};
    int dp[14000] = {};//dp[i]表示重量为i时的最大价值,记得清零
    for(int i=0;i<n;i++)
    {
        cin >> w[i] >> d[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=w[i];j--)//每次只会用到上一行的 左上方 的值，因此下标从右向左;剩余容量需要大于当前重量
        {
            dp[j] = max(dp[j], dp[j-w[i]] + d[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}