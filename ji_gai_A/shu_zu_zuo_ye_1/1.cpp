/*
郭大卫
1900012995
校门外的树
19.10.09
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int l, m, x1, x2, sum = 0;//l是马路长度，m是区域数目，x1是每个区间的起始点，x2是每个区间的结束点，sum为剩余数目总数
    int a[10001];
    cin >> l >> m;
    for (int k=0; k<=l; k++)//数组清零
    {
        a[k] = 0;
    }
    for (int i=0; i<m; i++)
    {
        cin >> x1 >> x2;
        for(int j=x1; j<=x2; j++)//将区间内的数标志为1
        {   
            a[j] = 1;
        }
        
    }
    for (int k=0; k<=l; k++)//遍历L上的所有数，如果该位置为0，则剩余树木的总数加一
    {
        if(a[k] == 0)
        sum++;
    }
    cout << sum << endl;
    system("PAUSE");
    return 0;
}