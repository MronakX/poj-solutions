/*
郭大卫
1900012995
统计整数的个数
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int a[101],b[101];
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int j=1;j<=n;j++)
    {
        for(int k=1;k<=n-j;k++)
        {
            if(a[k]>a[k+1])
            {
                swap(a[k],a[k+1]);
            }
        }
    }
    //从小到大排序完毕
    int cnt=1;
    for(int m=1;m<=n;m++)
    {
        if(a[m+1]==a[m])
        {
            cnt++;
        }
        else
        {
            cout << a[m] << ":" << cnt <<endl;
            cnt = 1;
        }
    }
    system("PAUSE");
    return 0;
}