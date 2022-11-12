#include <iostream>
#include <cstring>

using namespace std;

int a[110][110] = {};
int dp[110][110] = {};
int ans = -0x3f3f3f3f;
int main()
{
    int f, v;
    cin >> f >> v;
    for(int i=1; i<=f; i++)
    {
        for(int j=1; j<=v; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for(int i=1; i<=f; i++)
    {
        dp[i][i] = dp[i-1][i-1] + a[i][i];
    }

    for(int i=1; i<=f; i++)
    {
        for(int j=i+1; j<=v; j++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + a[i][j]);
        }
    }
    cout << dp[f][v] << endl;
    system("pause");
    return 0;
}