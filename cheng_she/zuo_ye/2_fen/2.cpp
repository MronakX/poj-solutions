#include <iostream>
#include <iomanip>
using namespace std;

const double pi = 3.1415926535897932384626;//精度要足够高，3.14159都不够。。
const double eps = 1e-6;

int main()
{
    double a[10010] = {};
    int n, f;
    cin >> n >> f;
    double R = 0, L = 0;
    for(int i=0;i<n;i++)//以R^2衡量体积
    {
        cin >> a[i];
        a[i] = a[i]*a[i];
        R = max(R, a[i]);
    }

    double last = 0;
    while(R - L >= eps)//注意半径可以是小数
    {
        double mid = L + (R-L)/2;
        int num = 0;
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            double tmp = a[i];
            while(tmp - mid >= eps)
            {
                tmp -= mid;
                num++;
                if(num >= f+1)//注意+1
                {
                    flag = 1;
                    i = n;
                    break;
                }
            }
        }
        if(flag)
        {
            last = mid;
            L = mid;
        }
        else
        {
            R = mid;
        }  
    }
    cout << fixed << setprecision(3) << pi*last << endl;

    system("pause");
    return 0;
}