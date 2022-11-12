#include <iostream>
#include <iomanip>
using namespace std;

int dp[40] = {};

int dfs(int x)
{
    int sum = 0;
    if(dp[x])
    {
        return dp[x];
    }
    if(x % 2 == 1)
    {
        return 0;
    }
    if(x == 2)
    {
        return 3;
    }
    if(x == 0)
    {
        return 1;
    }
    dp[x] = 4*dfs(x-2) - dfs(x-4);
    return dp[x];
}

int main()
{
    int x;
    while(1)
    {
        cin >> x;
        if(x == -1) break;
        cout << dfs(x) << endl;

    }
    system("pause");
    return 0;
}