#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int n;
    int a[120][120] = {};
    int b[120][120] = {};
    int dp[120] = {};
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }

    int ans = -(1<<30);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            b[i][j] = a[i][j] + b[i-1][j];
        }
    }

    for(int i=0; i<n; i++)//st
    {
        for(int j=i; j<n; j++)//ed
        {
            dp[0] = b[j][0] - b[i][0];
            for(int k=1; k<n; k++)
            {
                dp[k] = max(b[j][k] - b[i][k], b[j][k] - b[i][k] + dp[k-1]);
                ans = max(ans, dp[k]);
            }
        }
    }

    cout << ans << endl;
    system("pause");
    return 0;
}