        /*
        郭大卫
        1900012995
        滑雪
        19.11.20
        */
        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
        int m, n;
        int a[110][110] = {}, dp[110][110] = {};//dp初值设为0
        int skate(int i, int j)
        {
            if(dp[i][j])//dp不为0，则已经计算过，直接调取数值
            return dp[i][j];
            dp[i][j] = 1;//dp置为1，代表搜过
            if(a[i][j] > a[i+1][j] && i<m)//未越界，比相邻高，则取 本位置dp 与 相邻位置dp+1 的较大值
            {
                dp[i][j] = max(dp[i][j], skate(i+1,j)+1);
            }
            if(a[i][j] > a[i-1][j] && i>1)
            {
                dp[i][j] = max(dp[i][j], skate(i-1,j)+1);
            }
            if(a[i][j] > a[i][j+1] && j<n)
            {
                dp[i][j] = max(dp[i][j], skate(i,j+1)+1);
            }
            if(a[i][j] > a[i][j-1] && j>1)
            {
                dp[i][j] = max(dp[i][j], skate(i,j-1)+1);
            }
            return dp[i][j];
                }
        int main()
        {
            cin >> m >> n;
            for(int i=1; i<=m; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cin >> a[i][j];
                }
            }
            int maxlen = 0;
            for(int i=1; i<=m; i++)
            {
                for(int j=1; j<=n; j++)
                { 
                    maxlen = max(maxlen, skate(i,j));//取dp最大值
                }
            }
            cout << maxlen << endl;
            system("PAUSE");
            return 0;
        }