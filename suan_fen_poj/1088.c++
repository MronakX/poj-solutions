#include <iostream>
#include <cstring>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[110][110] = {};
int a[110][110] = {};
int m, n;

int dfs(int x, int y)
{
    if(dp[x][y])
        return dp[x][y];
    dp[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || ny<0 || nx >= m || ny >= n)
            continue;
        if(a[x][y] <= a[nx][ny])
            continue;
        dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
    }
    return dp[x][y];
}


int main()
{
    
    cin >> m >> n;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}