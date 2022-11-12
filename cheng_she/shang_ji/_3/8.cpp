#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100010] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;
        
        int L = 0, R = n-1;
        int mingap = 1000000000;
        int ans = 0;
        while(L <= R)
        {
            int mid = L+(R-L)/2;
            if(a[mid] == target)
            {
                ans = a[mid];
                break;
            }
            if(a[mid] > target)
            {
                R = mid-1;
                if(a[mid] - target < mingap)
                {
                    ans = a[mid];
                    mingap = a[mid] - target;
                }
                else if(a[mid] - target == mingap)
                {
                    ans = min(a[mid], ans);
                }
            }
            else if(a[mid] < target)
            {
                L = mid+1;
                if(target - a[mid] < mingap)
                {
                    ans = a[mid];
                    mingap = target - a[mid];
                }
                else if(target - a[mid] == mingap)
                {
                    ans = min(a[mid], ans);
                }
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}