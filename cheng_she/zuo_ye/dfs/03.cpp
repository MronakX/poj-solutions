/*
郭大卫
1900012995
DFS1 海贼王之伟大航路
DFS + 状态压缩剪枝
20.05.27
*/
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int minsum = 999999;
int cursum = 0;
int a[20][20] = {};
int been[20] = {};
int dp[20][1<<17] = {};//dp[i][j]，i表示curcity，j表示来时路径
int n;
//直接dfs超时，需要剪枝
void dfs(int curcity, int citynum, int pathstate)//curcity为当前所在，citynum为累计去过的城市。pathstate为所有岛屿去/没去的状态合计
{
    if(cursum >= minsum)//无论是否走完，已经超过最小值，剪枝
        return;
    if(citynum == n-1)//只剩终点没去过
    {
        minsum = min(minsum, cursum + a[curcity][n-1]);
        return;
    }
    if(dp[curcity][pathstate] <= cursum && dp[curcity][pathstate] != 0)//1->3->2 和 1->2->3的pathstate相同，且无后效性，故只要最小值，剪枝
    {
        return;
    }
    dp[curcity][pathstate] = cursum;
    for(int i=0;i<n-1;i++)
    {
        if(i!=curcity && been[i] == 0)
        {
            cursum += a[curcity][i];
            been[i] = 1;
            //cout << "from " << curcity << " to " << i << endl;
            //cout << "sum = " << cursum << endl;
            dfs(i, citynum + 1, pathstate + (1 << i));
            cursum -= a[curcity][i];
            been[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    been[0] = 1;
    dfs(0,1,1);
    cout << minsum << endl;
    return 0;
}