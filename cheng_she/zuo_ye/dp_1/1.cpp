/*
郭大卫
1900012995
动规1 —— 1
滑雪 二维最长下降序列 递归+dp记录
20.04.29
*/

#include <iostream>
#include <iomanip>
using namespace std;

int r, c;
int a[110][110]={};
int dp[110][110]={};
int dfs(int i, int j)
{
    if(dp[i][j])
        return dp[i][j];
    dp[i][j] = 1;
    if(a[i][j] > a[i+1][j] && i<r)//未越界，比相邻高，则取 本位置dp 与 相邻位置dp+1 的较大值
    {
        dp[i][j] = max(dp[i][j], dfs(i+1,j)+1);
    }
    if(a[i][j] > a[i-1][j] && i>1)
    {
        dp[i][j] = max(dp[i][j], dfs(i-1,j)+1);
    }
    if(a[i][j] > a[i][j+1] && j<c)
    {
        dp[i][j] = max(dp[i][j], dfs(i,j+1)+1);
    }
    if(a[i][j] > a[i][j-1] && j>1)
    {
        dp[i][j] = max(dp[i][j], dfs(i,j-1)+1);
    }
    return dp[i][j];
}

int main()
{
    cin >> r >> c;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin >> a[i][j];
        }
    }


    int maxlen = 0;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        { 
            maxlen = max(maxlen, dfs(i,j));//取dp最大值
        }
    }
    cout << maxlen << endl;
    system("pause");
    return 0;
}