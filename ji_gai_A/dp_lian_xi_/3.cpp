        /*
        郭大卫
        1900012995
        放苹果问题
        19.11.13
        */
        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
		int dp[110][20]={};
		int main()
		{
			int n, m, ans = 0;
			int a[100], dp[100][100]={};
			cin >> n >> m;
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=m;i++)
				{
					cin >> a[i];
					dp[i][i] = a[i];
				}
				for(int i=0;i<=m-1;i++)//
				{
					for(int j=1;j<=m-i;j++)//起点
					{
						int l = i+j;//终点
						dp[j][l] = max(dp[j+1][l] + a[j]*(m+j-l), dp[j][l-1] + a[l]*(m+j-l));
						//cout << j << " " << l << ":" << dp[j][l] << endl;
					}
				}
				ans += dp[1][m];
			}
			cout << ans << endl;
			
			system("PAUSE");
			return 0;
		} 