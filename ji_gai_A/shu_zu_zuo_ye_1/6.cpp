/*
郭大卫
1900012995
整数奇偶排序
19.10.09
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int i = 1;
    int a[12], b[12], c[12];//a为初始数组，b为奇数数组，c为偶数数组
    for(int z=1; z<=10; z++)//输入10个数，赋值给数组
    {
        cin >> a[z];
    }
    int j = 0;
    for(int i=1; i<=10; i++)
    {
        if(a[i]%2 == 1)
        {
            j++;
            b[j] = a[i];//如果a中有奇数，赋值给b
            
        }
    }
    int k = 0;
    for(int q=1; q<=10; q++)//同理偶数赋值给c
    {
        if(a[q]%2 == 0)
        {
            k++;
            c[k] = a[q];
            
        }
    }

    for(int g=1; g<=j; g++)//奇数冒泡，从大到小
    {
        for(int h=1; h<=j-g; h++)
        {
            if(b[h] < b[h+1])
            {
                swap(b[h], b[h+1]);
            }
        }
    }

    for(int w=1; w<=k; w++)//偶数冒泡，从小到大
    {
        for(int v=1; v<=k-w; v++)
        {
            if(c[v] > c[v+1])
            {
                swap(c[v], c[v+1]);
            }
        }
    }
    cout << b[1] ;//第一个数没空格
    for(int d=2; d<=j; d++)
    {
        cout << " " << b[d];
    }
    for(int e=1; e<=k; e++)
    {
        cout << " " << c[e];
    }
    system("PAUSE");
    return 0;
}