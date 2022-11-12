/*
郭大卫
1900012995
DFS1 棋盘问题
20.05.27
*/
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

char str[10][10] = {};
int a[10][10] = {};
int row[10] = {};
int n, k;
int cnt = 0;
void dfs(int col, int chesscnt)
{
    if(chesscnt == k)
    {
        cnt++;
        return;
    }
    if(col == n)
    {
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i][col] == 1 && row[i] == 0)
        {
            row[i] = 1;
            dfs(col+1, chesscnt+1);
            row[i] = 0;
        }
    }
    dfs(col+1, chesscnt);
    return;
}

int main()
{
    while(cin >> n >> k)
    {
        if(n == -1)
            break;
        memset(str,0,sizeof(str));
        memset(a,0,sizeof(a));
        memset(row,0,sizeof(row));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> str[i][j];
                if(str[i][j] == '.')
                {
                    a[i][j] = 0;
                }
                else
                {
                    a[i][j] = 1;
                }
                
            }
        }
        cnt = 0;
        dfs(0,0);
        cout << cnt << endl;
    }
    return 0;
}