/*
郭大卫
1900012995
打印极值点下标
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n, m , flag;
    int a[100];
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        flag = 0;
        cin >> m;
        for(int k=0;k<m;k++)
        {
            cin >> a[k];
        }
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                if(a[j]<a[1]||a[j]>a[1])
                {
                    cout << j;
                    flag = 1;
                }
            }
            if(j==m-1)
            {
                if((a[j]>a[j-1]||a[j]<a[j-1]) && flag==1)
                {
                    cout << " " << j;
                }
                if((a[j]>a[j-1]||a[j]<a[j-1]) && flag==0)
                {
                    cout << j;
                    flag = 1;
                }
                

            }
            if(j>0 && j<m-1)
            {
                if((a[j]>a[j-1] && a[j]>a[j+1]) || (a[j]<a[j-1] && a[j]<a[j+1]))
                {
                    if(flag == 1)
                    {
                        cout << " " << j;
                    }
                    if(flag == 0)
                    {
                        cout << j;
                        flag = 1;
                    }
                }
            }  
        }
        cout << endl;
    }
    system("PAUSE");
    return 0;
}