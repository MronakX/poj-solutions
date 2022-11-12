#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int l, m, x1, x2, sum=0;
    int a[10001];
    cin >> l >> m;
    for (int k=0;k<=l;k++)
    {
        a[k]=0;
    }
    for (int i=0;i<m;i++)
    {
        cin >> x1 >> x2;
        for(int j=x1;j<=x2;j++)
        {   
            a[j] = 1;
        }
        
    }
    for (int k=0;k<=l;k++)
    {
        if(a[k]==0)
        sum ++;
    }
    cout << sum << endl;
    
    system("PAUSE");
    return 0;
}