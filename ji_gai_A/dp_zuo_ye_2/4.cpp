        /*
        郭大卫
        1900012995
        最长等差数列子集
        19.11.27
        */
        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <stdio.h>
        #include <algorithm>
        using namespace std;
        int dp[5001][5001] = {};//dp[i][j]代表 数字i在以j为差的等差数列中的位置,默认为0；如2 4 6 则dp[6][2] = 2
        int b[5001][5001] = {};//b检测某个数是否在数组范围内
        int main()
        {
            int a[5001];
            int n;
            cin >> n;
            for(int i=0; i<n; i++)
            {
                cin >> a[i];
            }
            sort(a, a+n);//从小到大排序
            //这里用于特判最长数列为常数数列的情况
            int maxlength = 1;//常熟数列最长长度
            int cnt = 1;//中间值
            int special;//special为常数值
            for(int i=1; i<n; i++)
            {
                if(a[i] != a[i-1] || i == n-1)
                {
                    if(cnt > maxlength)
                    {
                        special = a[i-1];
                        maxlength = cnt;
                        cnt = 1;
                        continue;
                    }
                    cnt = 1;
                }
                if(a[i] == a[i-1])
                {
                    cnt++;
                }
            }            
            int jmax = a[n-1] - a[0];
            if(jmax == 0 && n >= 3)
            {
                cout << a[0];
                for(int i=1;i<n;i++)
                {
                    cout << "," << a[0];
                }
                exit(1);
            }
            for(int i=0; i<n; i++)//i为数组下标
            {
                for(int j=1; j<=jmax; j++)//j为差值，最大不超过原数列首尾之差
                {
                    b[a[i]][j] = 1;
                }
            }
            //动态转移方程，假如a[i]与a[i]-j均在原数列中，则dp[a[i]][j]的值 为 dp[a[i]-j][j]+1
            for(int i=1; i<n; i++)
            {
                for(int j=1; j<=a[i]; j++)
                {
                        if(b[a[i]-j][j] && b[a[i]][j])
                        {
                            dp[a[i]][j] = dp[a[i]-j][j] + 1;
                        }
                }
            }
            int amax = 1;//最长长度
            int end = 0;//最长数列最后一个数字
            int minus = 0;//差值
            for(int j=0; j<=a[n-1]; j++)//先循环差值，保证最后保存的一定是j的最大值
            {
                for(int i=0; i<n; i++)//再循环第一个数的下标，保证最后保存的首数字最大
                {
                    if(dp[a[i]][j] >= amax)//注意等号
                    {
                        amax = dp[a[i]][j];
                        minus = j;
                        end = a[i];
                    }
                }
            }    
            if(amax < 2 && maxlength <= 3)//最长长度小于3，则no
            {
                cout << "NO" << endl;
            }
            else if(maxlength > amax+1)//常数数列更长，则输出常熟数列
            {
                cout << special;
                for(int i=1; i<maxlength; i++)
                {
                    cout << "," << special;
                }
            }
            else
            {
                int start = end - minus * amax;//否则，求出首数字，并输出
                cout << start;
                for(int i=start+minus; i<=end; i+=minus)
                {
                    cout << "," << i;
                }
            }
            system("PAUSE");
            return 0;
        }