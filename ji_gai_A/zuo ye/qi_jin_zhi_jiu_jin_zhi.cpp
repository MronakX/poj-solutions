/*
郭大卫
1900012995
求特殊自然数
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n;
    cin >> n;
    for(int i=100;i<1000;i++)//在三位数区间枚举
    {
        if(i%7 == i/9/9%9 && i/7%7 == i/9%9 && i/7/7%7 == i%9)//某个十位数n转化为x位数，个位n%x,十位n/x%x,百位n/x/x%x...第一位1/x/x.../x/x%x
        {
            if(n==1) cout << i << endl;
            if(n==2) cout << i/7/7 << i/7%7 << i%7 <<endl;
            if(n==3) cout << i/9/9 << i/9%9 << i%9 <<endl;
        }
    }
    system("PAUSE");
    return 0;
}