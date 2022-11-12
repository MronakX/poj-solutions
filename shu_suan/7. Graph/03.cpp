/*
郭大卫
1900012995
兔子与樱花 floyd + 栈逆序输出路径
20.12.03
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;
#define INF 1<<20
map<string, int> str2int;
map<int, string> int2str;
int p;
struct D
{
    int dis = INF;
    int pre = -1;
}d[50][50] = {};

void init()
{
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<p; j++)
        {
            d[i][j].dis = INF;
            d[i][j].pre = -1;
        }
        d[i][i].dis = 0;
        d[i][i].pre = i;
    }
}

void floyd()
{
    for(int v=0; v<p; v++)
    {
        for(int i=0; i<p; i++)
        {
            for(int j=0; j<p; j++)
            {
                if(d[i][v].dis + d[v][j].dis < d[i][j].dis)//不能使用1<<30作为INF，因为这里有INF+INF
                {
                    d[i][j].dis = d[i][v].dis + d[v][j].dis;
                    d[i][j].pre = d[v][j].pre;
                }
            }
        }
    }
}

int main()
{
    cin >> p;
    for(int i=0; i<p; i++)
    {
        string str;
        cin >> str;
        str2int[str] = i;
        int2str[i] = str;
    }
    init();
    int q;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        string str1, str2;
        int num;
        cin >> str1 >> str2 >> num;
        d[str2int[str1]][str2int[str2]].dis = num;
        d[str2int[str2]][str2int[str1]].dis = num;
        d[str2int[str1]][str2int[str2]].pre = str2int[str1];
        d[str2int[str2]][str2int[str1]].pre = str2int[str2];
    }
    floyd();
    int r;
    cin >> r;
    while(r--)
    {
        stack<int> s;
        string str1, str2;
        cin >> str1 >> str2;
        int num1 = str2int[str1], num2 = str2int[str2];
        if(num1 == num2)
        {
            cout << int2str[num1] << endl;
            break;
        }
        s.push(num2);
        int pre = d[num1][num2].pre;
        while(pre != num1)
        {
            s.push(pre);
            pre = d[num1][pre].pre;
        }
        s.push(num1);
        int tmp;
        tmp = s.top();
        while(!s.empty())
        {
            s.pop();
            if(!s.empty())
            {
                cout << int2str[tmp] << "->(" << d[tmp][s.top()].dis << ")->";
                tmp = s.top();
            }
            else
            {
                cout << int2str[tmp] << endl;
                break;
            }
        }
    }
    system("pause");
    return 0;
}