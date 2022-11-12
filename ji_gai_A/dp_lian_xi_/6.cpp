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
        int main()
        {
            int n, teps, tepx, tepy, anss, ansx, ansy, start1, start2, start3;
            int a[100][100] = {}, b[100] = {}, dp[100] = {};
            cin >> n;
            for(int i=1; i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    cin >> a[i][j];
                }
            }
            int sum = 0, maxnum = 0;
            for(int i=1;i<=n;i++)//起始行
            {   
                memset(b, 0, sizeof(b));
                memset(dp, 0, sizeof(dp));
                for(int j=i;j<=n;j++)//起始行向下遍历
                {
                    for(int k=1;k<=n;k++)//转化为一维数组
                    {
                        b[k] += a[j][k];
                    }
                    for(int k=1;k<=n;k++)
                    {
                        if(b[k] + dp[k-1] <= b[k])
                        {
                            start1 = k;
                        }
                        dp[k] = max(b[k] + dp[k-1], b[k]);
                        if(dp[k] > maxnum)
                        {
                            maxnum = dp[k];
                            start2 = start1;
                            anss = i;
                            ansx = j;
                            ansy = k;
                        }
                        maxnum = max(maxnum, dp[k]);
                        //cout << maxnum << endl << endl;
                    }
                    if(maxnum > sum)
                    {
                        sum = maxnum;
                        start3 = start2;
                        teps = anss;
                        tepx = ansx;
                        tepy = ansy;
                    }
                }
            }
            //cout << start3;
            /*for(int i = teps;i<=tepx;i++)
            {
                cout << a[i][start3];
                for(int j=start3+1;j<=tepy;j++)
                {
                    cout << " " << a[i][j];
                }
                cout << endl;
            }*/
            cout << sum << endl;
            system("PAUSE");
            return 0;
        }