/*
郭大卫
1900012995
动规2 -- B:硬币
20.05.20
01背包方案总数 + 
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{   
    //TLE在60w左右，每次去掉一个硬币dp是n*n*(x-i),最大4*10^8,肯定TLE
    int n, x;
    cin >> n >> x;
    int a[220] = {};
    int dp[10010] = {1};//dp[i]代表体积为i时的方案数
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=x;j>=a[i];j--)//注意从右向左
        {
            dp[j] += dp[j-a[i]];//正常方案数
        }
    }
    int ans[220] = {};
    int cnt = 0;
    for(int i=0;i<n;i++)//每次去掉一个硬币
    {  
        int dp2[10010] = {};
        for(int j=0;j<=x;j++)
        {
            if(j-a[i] >= 0)
                dp2[j] = dp[j] - dp2[j-a[i]];
            else
                dp2[j] = dp[j];
        }
        if(dp2[x] == 0)
        {
            ans[cnt++] = a[i];
        }
    }
    if(!ans[0])
    {
        cout << 0 << endl << endl;
    }
    else
    {
        cout << cnt << endl;
        sort(ans, ans+cnt);
        cout << ans[0];
        for(int i=1;i<cnt;i++)
        {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    

    return 0;
}