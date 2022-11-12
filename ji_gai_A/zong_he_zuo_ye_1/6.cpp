		/*
		郭大卫
		1900012995
		旅行售货商问题
		19.12.12
		*/
		#include <iostream>
		#include <iomanip>
		#include <cmath>
		#include <cstring>
		#include <algorithm>
		using namespace std;
		int n;
		int mem[20] = {};//存储i城市是否去过
		int a[20][20] = {};
		int ans = 1000000;//最终答案
		int tans = 0;//当前开销总和
		void find(int times, int cur, int ini)//times为当前旅行城市数量，cur为所处城市，ini为初始城市
		{
			if(times == n)//旅行完毕，比较求出较小值
			{
				//cout << "ok" << endl;
				tans += a[cur][ini];
				ans = min(tans, ans);
				tans -= a[cur][ini];//回溯
				return;
			}
			else
			{
				for(int i=1; i<=n; i++)//下一步
				{
					//cout << "next step :" << i << endl;
					if(!mem[i] && i != ini && ((tans + a[cur][i]) < ans))//1.没去过 2.不是初始城市 3.已经比当前最小值大，剪枝
					{
						mem[i] = 1;
						tans += a[cur][i];
						//cout << i << " " << ini << endl;
						find(times + 1, i, ini);
						tans -= a[cur][i];//回溯
						mem[i] = 0;	
					}
				}
				return;
			}
			
		}
		int main()
		{
			cin >> n;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					cin >> a[i][j];
				}
			}
			find(1,1,1);
			cout << ans << endl;
			system("PAUSE");
			return 0;
		}