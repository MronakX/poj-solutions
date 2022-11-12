/*
郭大卫
1900012995
细菌的战争
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    long long n, a, b;//n为数据数量，a为有害菌初始个数，b为有益菌初始个数
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int g = 1; //每次天数归为1
        cin >> a >> b;
        while(a>b)//当a>b时，有害菌尚未消灭完全
        {
            a = (a-b)*2;//有害菌先被对应数量的有益菌消灭，之后存活的繁殖一倍
            b = b*1.05;//有益菌繁殖百分之五
            if(a > 1000000)
            {
                a = 1000000;//有害菌数量超过一百万时，归为一百万
            }
            g++;
        }
        cout << g << endl; 
    }
    system("PAUSE");
    return 0;
}