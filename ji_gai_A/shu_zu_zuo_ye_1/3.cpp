/*
郭大卫
1900012995
输出不重复的数字
19.10.09
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n, a[20001];//n为数据个数
    cin >> n;
    for(int i=1; i<=n; i++)//为数组赋值
    {
        cin >> a[i];
    }
    cout << a[1];//首先输出a1，防止空格格式错误
    for(int j=2; j<=n; j++)
    {
        int g = 1;//g用来标记是否重复
        for(int k=1; k<j; k++)
        {
            if(a[k] == a[j])//若在该数之前有重复，则标记为0
            {
                g = 0;
                break;
            }
        }
        if(g == 1)//标记为1时，进行输出
        cout << " " << a[j]; 
    }
    system("PAUSE");
    return 0;
}