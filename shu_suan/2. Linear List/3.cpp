/*
郭大卫
1900012995
Number Sequence dp + 较难的模拟
20.09.29
*/

#include <iostream>
#include <cstring>
#include <algorithm>    
#include <limits.h>
using namespace std;


long long num[45000] = {};
char a[400000] = {};
long long tot[45000] = {};
int main()
{
    num[1] = 1;
    tot[1] = 1;
    for(int i=2;i<=45000;i++)//i = 每一组lim; num[i] = 该数组总位数
    {
        if(i < 10)
            num[i] = num[i-1] + 1;
        else if(i >= 10 && i < 100)
            num[i] = num[i-1] + 2;
        else if(i >= 100 && i < 1000)
            num[i] = num[i-1] + 3;
        else if(i >= 1000 && i < 10000)
            num[i] = num[i-1] + 4;
        else 
            num[i] = num[i-1] + 5;
        //tot[i] = tot[i-1] + num[i];
    }
    int cnt = 1;
    for(int i=1;i<=45000;i++)
    {
        string str = to_string(i);
        int len = str.length();
        for(int j=0;j<len; j++)
        {
            a[cnt++] = str[j];
            //cout << "a" << cnt-1 << ":" << str[j] << endl;
        }
    }

    int n;
    cin >> n;
    while(n--)
    {
        int t;
        int ans = 0;
        cin >> t;
        int lim = 0;
        for(int i=1;i<=45000;i++)
        {
            t -= num[i];
            if(t <= 0)
            {
                t += num[i];
                lim = i;
                break;
            }
        }
        //1234... 第t位
        cout << a[t] << endl;
    }
    return 0;
}