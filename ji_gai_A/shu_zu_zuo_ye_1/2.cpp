/*
郭大卫
1900012995
辉辉的日程表
19.10.09
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n, start, end, t1, t2, flag;//n为数据个数；start，end为一次被接受的预约起始时间、终止时间；t1,t2是输入的预约时间；flag用于标记是否预约成功
    int a[22] = {};//数组清零

    cin >> n;

    cin >> start >> end;//第一组预约一定能成功
    cout << "Y" << endl;
    
    for(int i=1; i<n; i++)
    {
        for(int k=start; k<end; k++)//将预约的时间段标记为1
        {
            a[k]=1; 
        }
        cin >> t1 >> t2 ;
        flag = 1;//预约成功标记为1
        for(int j=t1; j<t2; j++)
        {
            if(a[j] == 1)//如果在这个时间段内，已有预约，则预约失败
            {
                cout << "N" << endl;
                flag = 0;//标记预约失败
                break;
            }
        }
        if(flag == 1)
        {
            cout << "Y" << endl;
            start = t1;//将该时间段作为新的预约区间，进行标记
            end = t2;
        }
    }
    system("PAUSE");
    return 0;
}