/*
郭大卫
1900012995
分数求和
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int j=1;
    double a[52],b[52];
    double num, cond, min, n, g=0;
    cin >> n >> min;
    for(int i=0;i<n;i++)
    {
        cin >> num >> cond;
        if(cond >=min)
        {
            g++;
            a[j] = num;
            b[j] = cond;
            j++;
        }
    }
    if(g==0)
    {
        cout << "None." << endl;
    }
    else
    {
        for(int k=1;k<=j-1;k++)
        {
            for(int l=1;l<j-1;l++)
            {
                if(b[l]<b[l+1])
                {
                    swap(a[l],a[l+1]);
                    swap(b[l],b[l+1]);
                }
                
            }
        }
    }
    for(int m=1;m<=j-1;m++)
    {   
        cout << fixed << setprecision(0);
        cout << setfill('0') << setw(3) << a[m] << " ";
        cout << fixed << setprecision(1) << b[m] <<endl;
    }
    
    system("PAUSE");
    return 0;
}