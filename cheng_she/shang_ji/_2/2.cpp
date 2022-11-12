#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int ans = 999999;
    int n;
    cin >> n;
    //长 宽 高 
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(!(n%(i*j)))
            {
                int k = n/i/j;
                int tmp = 2*i*j + 2*j*k + 2*k*i;
                ans = min(tmp, ans);
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}