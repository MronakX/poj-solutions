#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int a[150];
    int l,j,k,n,sum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            for(l=0;l<n;l++)
            {
                if(a[j]==a[k]+a[l] && k!=j && k!=l && j!=l)
                {
                    sum++;
                    break;
                }
            }
            if(a[j]==a[k]+a[l] && k!=j && k!=l && j!=l)
            {
                break;
            }
        }
    }
    cout << sum <<endl;
    system("PAUSE");
    return 0;
}