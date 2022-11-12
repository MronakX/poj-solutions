#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[50010] = {0};//a[0]= 0
    int l, n, m;//0, l 各有一个石头
    cin >> l >> n >> m;
    int L = 0, R = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        R = max(a[i],R);
    }
    a[n+1] = l;
    int lastdis = 0;
    while(L<=R)
    {
        int num = 0;
        int flag = 0;
        int mid = L+(R-L)/2;
        int prepoint = 0;//每次跳跃的起点
        for(int i=1; i<=n+1;i++)
        {
            if(a[i] - prepoint < mid)//超出距离，撤掉这块石头
            {
                num++;
            }
            else
            {
                prepoint = a[i];
            }
            if(num > m)//撤多了
            {
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            R = mid-1;
        }
        else
        {
            lastdis = mid;
            L = mid+1;
        }
    }

    cout << lastdis << endl;
    system("pause");
    return 0;
}