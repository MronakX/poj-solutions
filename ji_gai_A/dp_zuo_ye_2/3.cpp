		/*
        郭大卫
        1900012995
        矩阵取数游戏
        19.11.27
        */
        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
		int a[100], dp[100][100]={};//dp[i][j]代表：从i开始，到j截止的序列，剩余的最大价值
		int n, m, ans = 0;

		int choose(int i, int j)//同dp数组含义
		{
			if(dp[i][j])//记忆
			{
				return dp[i][j];
			}
			if(i == j)
			{
				return a[i]*(m-(j-i));//i=j,则只剩一个a[i]，价值为a[i]*被取的次序
			}
			dp[i][j] = max(choose(i+1,j) + a[i]*(m-(j-i)), choose(i,j-1) + a[j]*(m-(j-i)));//dp[i][j]为：1）取a[i]；2）取a[j] 二者中取最大值

			return dp[i][j];
		}

		int main()
		{
			cin >> n >> m;
			for(int k=1; k<=n; k++)//每一行互不影响，单独计算
			{
				memset(dp, 0, sizeof(dp));
				for(int i=1; i<=m; i++)
				{
					cin >> a[i];
				}
				ans += choose(1,m);
			}
			cout << ans << endl;
			
			system("PAUSE");
			return 0;
		} 