#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
//二分法注意:1.L<=R 注意等号 2.看清L,R代表数值 还是 下标
int n, c;
int x[100010] = {};

int main()
{   
    cin >> n >> c;
    //int R = 100/c;
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
    }
    sort(x, x+n);
    
    int R = x[n-1]/c;
    int L = 0;
    int lastpos = 0;
    while(R-L >= 0)//枚举D
    {
        int D = L+(R-L)/2;
        int flag = 0;
        int num = 1;
        int t = 0;
        int pre = x[0];
        for(int i=t;i<n;i++)//枚举N
        {
            if(x[i] - pre >= D)
            {
                num++;
                pre = x[i];
                t = i;
                if(num == c)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
        {
            lastpos = max(D, lastpos);
            L = D+1;
        }
        else
        {
            R = D-1;
        }
        
    }
    cout << lastpos << endl;
    system("pause");
    return 0;
}