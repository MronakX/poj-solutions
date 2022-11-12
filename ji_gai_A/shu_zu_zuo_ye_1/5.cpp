/*
郭大卫
1900012995
门诊计数
19.10.09
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n, a[30], queueTime, cnt;//n为人数，queueTime为当前排队截止时间，cnt为可门诊人数
    cin >> n;
    for(int i=1; i<=n; i++)//数组赋值
    {
        cin >> a[i];
    }
    for(int p=1; p<=n; p++)//冒泡，从小到大排序
    {
        for(int q=1; q<=n-p; q++)
        {
            if(a[q] > a[q+1])
            {
                swap(a[q], a[q+1]);
            }
        }
    }
    
    int advance = 0;//advance为9点前到的人数
    for(int j=1; j<=n; j++)
    {
        
        if(a[j] <= 60)//
        {
            
            advance ++;
        }
        queueTime = 10*advance + 60;//9点前到的所有人所需的排队时间
    }
    if(advance <= 12)//如果排了12个人以内，那么都可以成功门诊
    {
        cnt = advance;
    }
    if(advance > 12)//排了12个人以上，则只有12个人能排到
    {
        cnt = 12;
    }


    for(int k=advance+1; k<=n; k++)//对九点后到的人遍历
    {
        
        if(a[k] < queueTime && queueTime <= 180)//如果某个人到的时间比排队时间小，那么他必须在排队结束后再检查10分钟
        {
            
            queueTime = queueTime + 10;
            
        }
        if(a[k] >= queueTime && queueTime <= 180)//如果到的时间大于排队时间，那么他可立刻检查10分钟
        {
            queueTime = a[k]+10;
        }
        if(queueTime < 180)//当排队截止时间小于180，都可成功门诊
        {
            cnt++;
        }
        if(queueTime >= 180)//反之，则跳出循环
        {
            break;
        }
        
    }
    cout << cnt << endl;

    
    system("PAUSE");
    return 0;
}