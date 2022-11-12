#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    int num, cnt = 1, max, min; //num读入数据,cnt记录数据个数
    char ch; //保存读入的逗号，并没有用
    cin >> num; //读出第一个数字
    max = min = num; //最大值和最小的初值是第一个数据
    while(cin >> ch >> num) //循环读,没有数据可读则停止
    {
        if (num > max)
            max = num; //如果新读入的数据更大，则替换
        if (num < min)
            min = num; //如果新读入的数据更小，则替换
        cnt++; //被读入的数据个数加一
    }
    cout << cnt << endl << max - min << endl;
    system("PAUSE");
    return 0;
} 