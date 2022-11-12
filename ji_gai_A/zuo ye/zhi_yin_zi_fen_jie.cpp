/*
郭大卫
1900012995
整数的质因子分解
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n, g, x;//n为输入数，g为标记次数，x用于初始赋值
    cin >> n;
    x = n;//n在运算过程中会变，故赋值n给x
    for(int i=2;i<=x;i++)
    {
        g = 0;//g每次归零
        if(n%i == 0)//i为n的因数
        {
            while(n%i == 0)//当i是剩余因数的因数
            {
                n = n/i;//n为n的剩余因数
                g++;//标记+1
            }
            cout << i << " " << g << endl;    
        }
    }
    system("PAUSE");
    return 0;
}