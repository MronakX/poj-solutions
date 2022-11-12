#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    double a[10010] = {};
    int tmp[10010] = {};
    double L = 1, R = 0;//单位均为cm
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        a[i] *= 100;
        R = max(a[i], R);
    }
    double maxlen = 0;
    while(L <= R)
    {
        int mid = L + (R-L)/2;
        int num = 0;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            tmp[i] = a[i];
        }
        for(int i=0;i<n;i++)
        {
            while(tmp[i] >= mid)
            {
                tmp[i] -= mid;
                num++;
            }
            if(num >= k)
            {
                flag = 1;
            }
        }
        if(flag)
        {
            L = mid+1;
            maxlen = mid;
        }
        else
        {
            R = mid-1;
        }
    }
    if(maxlen)
        cout << fixed << setprecision(2) << maxlen/100 << endl;
    else
    {
        cout << "0.00" << endl;
    }
    
    system("pause");
    return 0;
}