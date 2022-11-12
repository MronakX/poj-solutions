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
			int n, m, minnum;
			while(cin >> n >> m)
			{
				for(int i=0;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
					{
						if(i==0) dp[i][j] = 0;
						else if(j==1) dp[i][j] = i;
						else
						{
							dp[i][j] = 100000000;
							for(int k=1; k<=i; k++)
							{
								minnum = max(dp[k-1][j-1], dp[i-k][j]) + 1;
								dp[i][j] = min(dp[i][j], minnum);
							}
						}
					}
				}
				cout << dp[n][m] << endl;
			}
			system("PAUSE");
			return 0;
		} 