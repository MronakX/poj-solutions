/*
郭大卫
1900012995
表达式·表达式树·表达式求值 
20.11.28
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

int graph[210][210] = {};
int mark[210] = {};
int n;
int ans = 0;
void prim(int s)
{
    mark[s] = 1;
    int cnt = 0;
    while(cnt < n-1)
    {
        int minlen = 1<<30;
        int pos = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1; j<=n;j++)
            {
                if(mark[i] != 0 && mark[j] == 0 && graph[i][j] != 0 && graph[i][j] < minlen)
                {
                    minlen = graph[i][j];
                    pos = j;
                }
            }
        }
        mark[pos] = 1;
        ans += minlen;
        cnt++;
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<n; i++)
    {
        char in;
        cin >> in;
        int num;
        cin >> num;
        while(num--)
        {
            char out;
            cin >> out;
            int len;
            cin >> len;
            graph[in-'A'+1][out-'A'+1] = graph[out-'A'+1][in-'A'+1] = len;
        }
    }    
    prim(1);
    cout << ans << endl;
    system("pause");
    return 0;
}