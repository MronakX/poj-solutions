        /*
        郭大卫
        1900012995
        求数组不相邻元素之和的最大值
        19.11.20
        */
        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
        int n, a[10010] = {}, dp[10010] = {};//dp记录重复值，初值为0

        //从后向前取值，注意到，取ai，则第ai-1不能取,从ai-2开始随意取; 不取ai，则从ai-1开始随意取。
        //因此，前i个数的最大值就是：1）不取ai，则为前i-1个数字的最大值；2)取ai，则为前i-2个数字的最大值加上ai
        int maxsum(int i)//i是数组中元素下标
        {
            if(dp[i])//已经计算过该下标对应的函数返回值，则直接调取
            {
                return dp[i];
            }
            if(i == 0)//只有a0，则最大值为a0
            {
                dp[i] = a[0];//记录函数返回值，下同
            }
            else if(i == 1)//a0和a1不能同时取,则取最大值
            {
                dp[i] = max(a[0], a[1]);
            }
            else//如上，有状态转移方程
            {
                dp[i] = max((maxsum(i-2) + a[i]), maxsum(i-1));
            }
            //cout << dp[i] << " ";
            return dp[i];
        }
        int main()
        {
            cin >> n;
            for(int i=0; i<n; i++)
            {
                cin >> a[i];
            }
            cout << maxsum(n-1) <<endl;
            system("PAUSE");
            return 0;
        }