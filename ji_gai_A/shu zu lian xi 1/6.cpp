/*
郭大卫
1900012995
打印日历
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;

    int theYear(int year)//判断年份
    {
        if((year % 4 == 0 && year % 100  !=0) || year%400 == 0)
            return 366;
        else
            return 365;
    }

    int theMonth(int year, int month)
    {
        if(month == 2 && theYear(year)==365)
            return 28;
        if(month == 2 && theYear(year)==366)
            return 29;
        if(month == 1||month==3||month==5||month==7||month==8||month==10||month==12)
            return 31;
        if(month == 4||month==6||month==9||month==11)
            return 30;
    }
     

    int theDay(int year, int month)
    {
        int sum = 0;
        for(int i = 1900;i<year;i++)
        {
            sum = sum + theYear(i);
        }
        for(int j = 1;j<month;j++)
        {
            sum = sum + theMonth(year, j);
        }

        return sum;
    }

    void outputCalendar(int year , int month)
    {
        int today, total, blank;
        cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
        int sum = theDay(year, month)+1;
        today = sum%7;//第一天是周几
        blank = today;//第一行空格
        total = theMonth(year, month);//一共多少天
        for(int i=0;i<blank;i++)
        {
            cout << "    ";
        }
        for(int j=1, k=j+today;j<=total;j++)
        {
            cout <<setw(4)<<j;
            if(k%7==0 || j == total)
            {
                cout << endl;
            }
            k++;
        }
    }

int main()
{
        int year, month;
        cin >> year >> month;
        outputCalendar(year,month);
    
    system("PAUSE");
    return 0;
}