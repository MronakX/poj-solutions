#include <iostream>
#include <cstring>

using namespace std;



int main()
{
    int n;
    cin >> n;
    int a[110][110] = {};
    int dp[110][110] = {};

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cin >> a[i][j];
            dp[i][j] = a[i][j];
        }
    }

    for(int i=n-1; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
            dp[i][j] += a[i][j];
        }
    }
    cout << dp[1][1] << endl;
    system("pause");
    return 0;
}