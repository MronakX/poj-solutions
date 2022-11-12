/*
郭大卫
1900012995
动规2 -- D:课程大作业
20.05.22
记录路径的TSP旅行商问题 状态压缩DP(位运算)
debug注意括号位置！！！！！！！！！
debug注意括号位置！！！！！！！！！
debug注意括号位置！！！！！！！！！
debug注意括号位置！！！！！！！！！
debug注意括号位置！！！！！！！！！
*/
#include <iostream>
#include <string>
#include <cstring>
#include <bitset>

using namespace std;
const int INF = 1 << 20;
struct work
{
    string name;
    int date; //ddl
    int cost;
} a[20] = {};

int dp[1 << 16] = {};      //dp[i]表示状态为i时（0未完成 1完成）的最小扣分
int totaltime[1 << 16] = {}; //当前花费的总时间

int prestatus[1 << 16] = {}; //当前状态上一步的状态，便于记录路径
int path[1 << 16] = {};      //当前状态下最后完成的作业编号

//由于对特定的i，总完成时间总是固定的，因此每个状态的endtime是无后效性的，只需考虑cost最小。实质是旅行商问题
//循环j为作业编号，i-(1<<j)为i状态没做j前的状态
//则dp[i] = min(dp[i-(1<<j) + max(endtime[i-(1<<j)] + a[j].cost - a[j].date , 0) , dp[i])
//相等时，选择字典序小的

void make_path(string *mypath, int pre) //根据prestatus倒推，倒序生成当前路程
{
    int cnt = 0;
    while (pre != 0)
    {
        mypath[cnt++] = a[path[pre]].name;
        pre = prestatus[pre];
    }
}

bool cmp_path(string *a, string *b) //a<b = true
{
    int cnt = 18;
    //cout << a[2] << a[1] << a[0] << endl;
    //cout << b[2] << b[1] << b[0] << endl;
    while (1)
    {
        if (a[cnt] > b[cnt])
            return false;
        else if (a[cnt] < b[cnt])
            return true;
        if (cnt == 0)
            break;
        cnt--;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        memset(totaltime, 0, sizeof(totaltime));
        memset(prestatus, 0, sizeof(prestatus));
        memset(path, 0, sizeof(path));
        int n;
        cin >> n;
        string tmp1;
        int tmp2, tmp3;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp1 >> tmp2 >> tmp3; //初始化a的时候把a.name初始化成""了，因此不能使用cin赋值
            a[i].name = tmp1;
            a[i].date = tmp2;
            a[i].cost = tmp3;
        }
        for (int i = 1; i < (1 << n); i++)
        {
            dp[i] = INF;
        }
        for (int i = 1; i < (1 << n); i++) //完成状态，最多2^15-1；从小到大，保证dp[i-(1<<j)]都已被更新
        {
            for (int j = 0; j < n; j++) //作业编号
            {
                if ((i >> j) & 1) //如果该情况下，该编号的作业已经完成，该位为1,可以从i-(1<<j)这一状态达到i状态
                {
                    //cout << dp[i-(1<<j)].endtime + a[j].cost - a[j].date << endl;
                    //cout << "prestatus = " << bitset<16>(i-(1<<j)) << " lastcost = " << dp[i-(1<<j)].endtime + a[j].cost - a[j].date << endl;
                    if (dp[i] == max(dp[i - (1 << j)] + totaltime[i - (1 << j)] + a[j].cost - a[j].date, 0)) //相等时，字典序优先
                    {
                        string prepath[20] = {}, thispath[20] = {};
                        make_path(prepath, i - (1 << j));
                        make_path(thispath, prestatus[i]);
                        /*for(int i=19;i>=0;i--)
                        {
                            cout << prepath[i];
                        }
                        cout << endl;
                        for(int i=19;i>=0;i--)
                        {
                            cout << thispath[i];
                        }
                        cout << endl;*/
                        if (cmp_path(prepath, thispath))
                        {
                            totaltime[i] = totaltime[i - (1 << j)] + a[j].cost;
                            path[i] = j;
                            prestatus[i] = i - (1 << j);
                        }
                    }
                    else if (dp[i] > max(dp[i - (1 << j)] + totaltime[i - (1 << j)] + a[j].cost - a[j].date, 0))
                    {
                        dp[i] = dp[i - (1 << j)] + max(totaltime[i - (1 << j)] + a[j].cost - a[j].date, 0);
                        totaltime[i] = totaltime[i - (1 << j)] + a[j].cost;
                        path[i] = j;
                        prestatus[i] = i - (1 << j);
                    }
                }
            }
        }
        string ans[20] = {};
        make_path(ans, (1 << n) - 1);
        cout << dp[(1 << n) - 1] << endl;
        for (int i = n - 1; i >= 0; i--)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}