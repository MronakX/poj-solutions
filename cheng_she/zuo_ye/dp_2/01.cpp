/*
郭大卫
1900012995
动规2 -- A:UNIMODAL PALINDROMIC DECOMPOSITIONS
20.05.20
峰形回文数组数量 每次去除两侧，分解
*/


#include <iostream>
using namespace std;

long long dp[500][500];
//dp[i][j]代表总和为i的数字，两侧以j开头时 的回文串数量；j<=i/2
//e.g dp[6][1] 代表141 11211 1221 111111 共四种
//dp[n][n] = 1; dp[n][n/2] = 1;
//状态转移方程为dp[i][j] = dp[i-j*2][1]+dp[i-j*2][2] + ... + dp[i-j*2][i-j*2]，答案为dp[i]一行总和
int main()
{
    int n;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[4][1] = 2;
    dp[4][2] = 1;
    for(int i=0;i<255;i++)
    {
        dp[i][i] = 1;
        if(i%2 == 0)
        {
            dp[i][i/2] = 1;
        } 
    }
    for(int i=1;i<255;i++)//
    {
        int k = i/2;
        for(int j=k-1;j>=1;j--)//最终目标为dp[n][1]，外层从小到大，里层从大到小
        {
            long long tmp = 0;
            for(int m=j;m<=i-j*2;m++)
            {
                tmp += dp[i-j*2][m];
            }
            dp[i][j] = tmp;
        }
    }
    while(1)
    {
        cin >> n;
        if(n == 0) break;
        cout << n << " ";
        long long ans = 0;
        for(int i=1;i<=n;i++)
        {
            ans += dp[n][i];
        }
        cout << ans << endl;
    }
    return 0;
}