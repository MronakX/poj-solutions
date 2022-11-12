#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n, max = 0, sum = 0;
    int a[1000000];
    cin >>n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int j=2;j<=n;j++)
    {
        if(a[j]>a[j-1])
        {
            max++;
        }
        if(a[j]<=a[j-1])
        {
            if(max>sum)
            {
                sum = max;
            }
            max = 0;
        }
    }
    cout << sum <<endl;
    system("PAUSE");
    return 0;
}