/*
郭大卫
1900012995
花生问题
19.12.18
*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct peanut{
    int x, y, num;
};

bool cmp(peanut a, peanut b)//从大到小排序
{
    return a.num > b.num;
}
int main()
{
    int q;
    cin >> q;
    for(int p=0; p<q; p++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int a[25][25] = {};
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin >> a[i][j];
            }
        }
        peanut pea[25] = {};
        int cnt = 0;
        for(int i=1; i<=n; i++)//记录花生的位置与数量
        {
            for(int j=1; j<=m; j++)
            {
                if(a[i][j])
                {
                    pea[cnt].x = i;
                    pea[cnt].y = j;
                    pea[cnt].num = a[i][j];
                    cnt++;
                }
            }
        }
        sort(pea, pea+cnt, cmp);//根据花生数量排序
        int curtime = 0;
        int curnum = 0;
        int maxnum = 0;
        for(int i=0; i<cnt; i++)//停止位置
        {
            curtime += pea[0].x;
            curtime += pea[i].x;
            curtime += 1;//取第一个位置，单独写出
            for(int j=1;j<=i;j++)
            {
                curtime += abs(pea[j].x - pea[j-1].x);
                curtime += abs(pea[j].y - pea[j-1].y);
                curtime += 1;
            }
            if(curtime <= k)
            {
                for(int j=0; j<=i; j++)
                {
                    curnum += pea[j].num;
                }
                maxnum = curnum;
                curnum = 0;
                curtime = 0;
            }
            else//超时，break
            {
                break;
            }
        }
        cout << maxnum << endl;
    }
    system("PAUSE");
    return 0;
}