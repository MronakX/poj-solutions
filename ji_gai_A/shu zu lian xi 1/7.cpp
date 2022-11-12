/*
郭大卫
1900012995
区间合并2.0
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n;
    int a[100002], b[100002], c[200001]={};
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }

    for(int m=1;m<=n;m++)
    {
        for(int n=2*a[m];n<=2*b[m];n++)
        {
            c[n]=1;
        }
    }

    for(int j=1;j<=n;j++)
    {
        for(int k=1;k<=n-j;k++)//冒泡排序，求最大值最小值
        {
            if(a[k] > a[k+1])
            {
                swap(a[k],a[k+1]);
            }
            if(b[k] < b[k+1])
            {
                swap(b[k],b[k+1]);
            }
        }
    }
    int min = 2*a[1];
    int max = 2*b[1];
    int flag = 0;
    for(int p = min; p <= max; p++)
    {
        if(c[p]==0 && c[p-1]==1 && c[p+1]==1)
        {
            cout << (p-1)/2 << " " << (p+1)/2 << endl;
            flag =1;
            continue;
        }
        if((c[p]==0 && c[p-1]==1))
        {
            cout << (p-1)/2 << " ";
            flag = 1;
        }
        if((c[p]==0 && c[p+1]==1))
        {
            flag = 1;
            cout << (p+1)/2 << endl;
        }
    }

    if(flag == 0)
    {
        cout << "Not Needed" << endl;
    }
    system("PAUSE");
    return 0;
}