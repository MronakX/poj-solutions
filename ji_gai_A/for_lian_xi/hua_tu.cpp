/*
郭大卫
1900012995
画矩形
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int w, h, flag;
    char x;
    while(1)
    {
        cin >> h >> w >> x >> flag;//h为高，w为宽度，x为输入符号，flag为标记
        if (flag == 1)
        {
            for(int i=0; i<h; i++)//画h行
            {
                cout << setw(w) << setfill(x) << x <<endl;//输出w个x
            } 
        } 
        if (flag == 0)
        {
            for(int j=0; j<h; j++)//画h行
            {
                if(j==0||j==h-1)//第一行和最后一行时
                {
                    cout << setw(w) << setfill(x) << x << endl;//输出w个x
                }
                else
                cout << x << setw(w-1) << setfill(' ') << x << endl;//否则，输出1个x,w-2个空格，1个x
            }
        }
        if (h==0)//输入0，结束
        break;
    }
    system("PAUSE");
    return 0;
}