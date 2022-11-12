/*
郭大卫
1900012995
排队看病
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n, a[1001],b[1001];
    double avr;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i] = i;
    }
    for(int j=1;j<=n;j++)
    {
        for(int k=1;k<=n-j;k++)
        {
            if(a[k]>a[k+1])
            {
            swap(a[k],a[k+1]);
            swap(b[k],b[k+1]);
            }
        }
    }
    for(int m=1;m<n;m++)
    {
        cout << b[m] << " ";
    }
    cout << b[n] << endl;
    double sum = 0;
    for(int p=1;p<=n;p++)
    {
        sum = sum + a[p]*(n-p);
    }
    avr = sum/n;
    cout << fixed << setprecision(2) << avr << endl;
    system("PAUSE");
    return 0;
}