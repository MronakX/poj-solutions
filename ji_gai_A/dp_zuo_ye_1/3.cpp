        /*
        郭大卫
        1900012995
        采药
        19.11.20
        */
        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
        int main()
        {
            int t, m;//t为时间上限，m为个数
            int w[110] = {}, v[110] = {}, dp[110][1020] = {};//w为单个草药所需时间，v为价值,dp[i][j]表示搜索到第i个草药，还有j时间情况下的总价值
            cin >> t >> m;
            for(int i=1; i<=m; i++)
            {
                cin >> w[i] >> v[i];
            }
            for(int i=1; i<=m; i++)//第i个草药
            {
                for(int j=0; j<=t; j++)//剩余时间
                {
                    if(j < w[i])//剩余时间不足，不取，价值不变
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else//否则，取最优子状态
                    {
                        dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
                    }
                }
            }
            int maxvalue = 0;
            for(int i=1; i<=m; i++)
            {
                for(int j=0; j<=t; j++)
                {
                    maxvalue = max(maxvalue, dp[i][j]);
                }
            }
            cout << maxvalue << endl;
            system("PAUSE");
            return 0;
        }