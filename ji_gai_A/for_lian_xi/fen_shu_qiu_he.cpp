/*
郭大卫
1900012995
分数求和
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n,x,y,sum1, sum2,fenzi1,fenmu1,max;//n为组数，x,y为分子，分母，sum1,sum2为通分后分子，分母，fenzi1，fenmu1是第一个数字的分子，分母，max是分子分母的较大值
    char q,p;//q,p为符号输入
    cin >> n;
    cin >> sum1 >> q >> sum2;//输入第一组数据
    for(int i=1;i<n;i++)//n-1次循环
    {
        cin >> x >> p >> y;
        sum1 = sum1*y+sum2*x;//分子通分
        sum2 = sum2*y;//分母通分
    }
    if(sum1>sum2)
    {
        max = sum1;
    }
    else
    {
        max = sum2;
    }
    for(int i=2;i<=max;i++)
    if(sum1%i==0 && sum2%i==0)//分子分母有公因数
    {
        while(sum1%i==0 && sum2%i==0)//多次检验此公因数
        {
        sum1 = sum1/i;
        sum2 = sum2/i;//约分
        }
    }
    if(sum1%sum2==0)
    cout << sum1/sum2 << endl;//当分子是分母的倍数，将分数转化为整数形式
    else
    {
    cout << sum1 << p << sum2;
    }
    system("PAUSE");
    return 0;
}