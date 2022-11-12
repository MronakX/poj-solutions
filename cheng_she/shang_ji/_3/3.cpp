#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a[1010] = {};
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<n;i++)//fenzi xiabiao
    {
        for(int j=i+1;j<n;j++)
        {
            int flag = 0;
            for(int k=2;k<=a[i];k++)
            {
                if(a[i]%k == 0 && a[j]%k == 0)
                {
                    flag = 1;
                }
            }
            if(!flag)
            {
                ans++;
                //cout << a[i] << "/" << a[j] << endl;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}