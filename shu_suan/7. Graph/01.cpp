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

int graph[1010][1010] = {};
int in[1010] = {};
int main()
{
    int v, a;
    cin >> v >> a;
    for(int i=0; i<a; i++)
    {   
        int s, e;
        cin >> s >> e;
        graph[s][e] = 1;
        in[e] ++;
    } 
    int cnt = 0;
    while(cnt != v)
    {
        int tmp;
        for(int i=1; i<=v; i++)
        {
            if(in[i] == 0)
            {
                tmp = i;
                in[i] = -1;
                cout << "v" << i << " ";
                cnt++;
                break;
            }
        }
        for(int i=1; i<=v; i++)
        {
            if(graph[tmp][i])
            {
                in[i]--;
                graph[tmp][i]--;
            }
        }
    }
    system("pause");
    return 0;
}