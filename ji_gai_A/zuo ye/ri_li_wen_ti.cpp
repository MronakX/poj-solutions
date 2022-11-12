#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    //年份
    while(1)
    {
        cin >> x;
        n = (x/365)+1;
        for(int i=0;i<n;i++)
        {
            if((i%4==0 && i%100!=0) || i%400==0)
            {
                x-=366;
            }
            else
            {
                x-=365;
            }
            if(x<0)//不确定有没有等号
            {
                break;
            }
        }
        year = i;
    }
    //月份
    
}