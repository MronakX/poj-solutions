/*
        郭大卫
        1900012995
        佳佳的筷子
        19.11.27
        */

        #include <iostream>
        #include <iomanip>
        #include <math.h>
        #include <cstring>
        using namespace std;
        int a[5001] = {}, dp[5001][2001]; //dp[i][j]代表 前i根筷子，选j组筷子，对应的坏值

        int main()
        {
            int n, k;
            cin >> n >> k;
            for(int i=1; i<=n; i++)
            {
                cin >> a[i];
            }
            for(int i=1; i<=n; i++)//倒序排序
                for(int j=1; j<=n-i; j++)
                {
                    if(a[j] < a[j+1])
                    {
                        swap(a[j], a[j+1]);
                    }
                }
            for(int i=0; i<=n; i++)
            {
                dp[i][0] = 0;
            }
            dp[0][0] = 0;
			//要令坏值最小，则每组中较短的两根筷子必然长度相邻
			//前i根筷子中取j组，分为两种情况：1）不选第i根：前i-1根中选j组；2）选第i根：前i-2根中选i-1组，并且选择第i-1和第i根；去最小值
            for(int i=1; i<=n; i++)//筷子数
                for(int j=1; j<=k; j++)//筷子组数
                {
                    if(i < 3*j)//因为是倒序排列，并且第三根筷子比另外两根都要大，因此前j组筷子一定至少包含3*i个筷子
                    {
                        dp[i][j] = 100000000;
                    }
                    if(i == 3*j)//刚好相等，说明前i根筷子已经构成j组筷子,而i，i-1又为其中最短，故这两根一定计算在内，故为情况2
                    {
                        dp[i][j] = dp[i-2][j-1] + (a[i]-a[i-1]) * (a[i]-a[i-1]);
                    }
                    if(i > 3*j)
                    {
                        dp[i][j] = min(dp[i-2][j-1] + (a[i]-a[i-1]) * (a[i]-a[i-1]), dp[i-1][j]);
                    }
                }
            cout << dp[n][k] << endl;
            
            return 0;
		}