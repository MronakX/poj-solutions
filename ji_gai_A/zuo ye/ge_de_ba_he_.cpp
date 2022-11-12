#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    int n, temp1, temp2;
    cin >> n;
    for(int i=3;i<=n/2;i+=2)//枚举较小的奇数，小于n/2
    {   
        int flag1=1,flag2=1;
        for(int j=2;j<=sqrt(i);j++)//枚举验证素数
        {
            if(i%j==0)
            {   
                flag1 = 0;
                break;//如果有质因数，标记，并停止循环
            }
        }
        if(flag1==1)//未被标记，则i为质数
        {
            temp1 = i;
        
        for(int k=2;k<=sqrt(n-temp1);k++)
        {
            if((n-temp1)%k==0)
            {
                flag2 = 0;
                break;
            }
        }
        }
        if(flag1==1 && flag2==1)
        {
            cout << temp1 << " " << n-temp1 << endl;
        }
    }
    system("PAUSE");
    return 0;
}