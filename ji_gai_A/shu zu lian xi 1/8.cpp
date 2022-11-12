/*
郭大卫
1900012995
小西天志愿者选拔
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n, m, rank, minScore;
    int a[5001], b[5001], c[5001], d[5001];
    cin >> n >> m;
    rank = 1.5*m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
    }

    for(int j=1;j<=n;j++)
    {
        for(int k=1;k<=n-j;k++)
        {
            if(b[k] < b[k+1])
            {
                swap(b[k],b[k+1]);
                swap(a[k],a[k+1]);               
            }
        }
    }
    for(int s=1;s<=n;s++)
    {
        for(int t=1;t<=n-s;t++)
        {
            if(b[t] == b[t+1] && a[t]>a[t+1])
            {
                swap(b[t],b[t+1]);
                swap(a[t],a[t+1]);               
            }
        }
    }
    
    minScore = b[rank];
    int sum = 0;
    for(int m=1;m<=n;m++)
    {
        if(b[m]>=minScore)
        {
        sum ++;
        }
    }

    cout << minScore << " " << sum << endl;
    for(int w=1;w<=sum;w++)
    cout << a[w] << " " << b[w] << endl;
    system("PAUSE");
    return 0;
}