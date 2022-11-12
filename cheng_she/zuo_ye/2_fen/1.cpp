#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N, M;
    int a[100010] = {};
    int L = 0, R = 0;//L,R 为最小开支的大小，L为所有开销最小值，R为总和。用二分查找
    cin >> N >> M;
    for(int i=0;i<N;i++)//o(n) 输入过程就中找到L，R
    {
        cin >> a[i];
        L = max(L, a[i]);
        R += a[i];
    }
    int lastpos = 0;
    while(L <= R)//二分查找
    {
        int mid = L+ (R-L)/2;
        int flag = 0;
        int num = 1;//月份数量，只可少，不可多
        int money = a[0];//某个fajo月的总开销
        for(int i=1;i<N;i++)
        {
            int tmp = money + a[i];
            if(tmp > mid)//超钱了，开一个新月
            {
                num++;
                money = a[i];
            }
            else
            {
                money = tmp;
            }
            if(num > M)//月数超限制，说明开支小了，L变化
            {
                flag = 1;
            }
        }
        if(flag)
        {
            L = mid+1;
        }
        else//否则，记录，向下继续试
        {
            R = mid-1;
            lastpos = mid;
        }
        
    }
    cout << lastpos << endl;
    system("pause");
    return 0;
}