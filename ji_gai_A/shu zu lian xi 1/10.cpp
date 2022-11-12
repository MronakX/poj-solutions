/*
郭大卫
1900012995
啤酒厂选址
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    long long n, min, money, num;
    int a[10001],b[10001];//a为需求量，b为距离
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }

    for(int j=0;j<n;j++)//枚举，j为当此枚举的起始居民点
    {
        money = 0;
        for(int k=0;k<n;k++)
        {
            int sum = 0, sum1 = 0, sum2 = 0;//1为顺时针距离，2为逆时针距离
            if(k==j)
            {
                continue;
            }

            if(j<k)
            {
                for(int p=j;p<=k-1;p++)
                {
                    sum1 += b[p];
                }
                for(int q=k;q<=n-1;q++)
                {
                    sum2 += b[q];
                }
                for(int r=0;r<=j-1;r++)
                {
                    sum2 += b[r];
                }
            }

            if(k<j)
            {
                for(int w=0; w<=k-1;w++)
                {
                    sum1 += b[w];
                }
                for(int x=j;x<=n-1;x++)
                {
                    sum1 += b[x];
                }
                for(int v=k;v<=j-1;v++)
                {
                    sum2 += b[v];
                }
            }
            
            if(sum1>=sum2)
            {
                sum = sum2;
            }
            if(sum1<sum2)
            {
                sum = sum1;
            }
            money = money + sum*a[k];
            //cout << j <<" " << k << " " << sum1 << " " << sum2 << " " << sum << " " << money << endl;
        }
        if(j==0)
        {
            min = money;
            num = 0;
        }       
        if(j!=0)
        {
            if(money < min)
            {
                min = money;
                num = j;
            }
        }
    }
    cout << num << "," << min << endl;
    system("PAUSE");
    return 0; 
}