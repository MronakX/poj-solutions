/*
郭大卫
1900012995
动规1 —— 3
怪盗基德（最长下降子序列）
20.04.29
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int i=0;i<k;i++)
    {   
        int n;
        int a[110] = {};
        int dpup[110] = {};
        int dpdown[110] ={};
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> a[j];
            dpup[j] = 1;
            dpdown[j] = 1;
        }
        int ans = -1;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1; k<n;k++)
            {
                if(a[k] < a[j])
                {
                    dpdown[k] = max(dpdown[k], dpdown[j]+1);
                }
                if(a[k] > a[j])
                {
                    dpup[k] = max(dpup[k], dpup[j]+1);
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            ans = max(ans, dpdown[j]);
            ans = max(ans, dpup[j]);
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}