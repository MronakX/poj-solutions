#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int a[1010] = {};
        int maxnum = 0;
        int sum = 0;
        double ans = 0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            maxnum = max(a[i], maxnum);
            sum+=a[i];
        }
        int rest = sum - maxnum;
        if(rest >= maxnum)
        {
            ans = sum/2.0;
        }
        else
        {
            ans = rest/1.0;
        }
        cout << fixed << setprecision(1) << ans << endl;
    }
    system("pause");
    return 0;
}