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
#include <algorithm>

using namespace std;

struct cow
{
    int a, b, num;
};

bool cmpa(cow a, cow b)
{
    return a.a > b.a;
}

bool cmpb(cow a, cow b)
{
    return a.b > b.b;
}
cow c[50010] = {};
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i<n;i++)
    {
        cin >> c[i].a >> c[i].b;
        c[i].num = i+1;
    }
    sort(c, c+n, cmpa);
    sort(c, c+k, cmpb);
    cout << c[0].num << endl;
    system("pause");
    return 0;
}