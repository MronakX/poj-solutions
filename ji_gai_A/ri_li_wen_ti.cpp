/*
郭大卫
1900012995
分数求和
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

    int ambYearDay (int year)
    {
        int sum=0;
        for(int i=2000;i<year;i++)
        {
            sum += theYear(i);
        }
        return sum;
    }
    int theMonth(int year, int month)
    {
        if(month == 0)
            return 0;
        if(month == 2 && theYear(year)==365)
            return 28;
        if(month == 2 && theYear(year)==366)
            return 29;
        if(month == 1||month==3||month==5||month==7||month==8||month==10||month==12)
            return 31;
        if(month == 4||month==6||month==9||month==11)
            return 30;
    }

    int monthTotal(int year, int month)
    {
        int sum = 0;
        for(int i=0;i<=month;i++)
        {
            sum = sum + theMonth(year, i);
        }
        return sum;
    }
int main()
{
    int day, month, year, g;
    while(cin >> day)
    {
        g = day%7;
        if(day != -1)
        {
        for(int i=2000;i<=9999;i++)
        {
            if(day >= ambYearDay(i) && day < ambYearDay(i+1))
            {
                year = i;
                day = day - ambYearDay(i);
                break;
            }
        }
    
        for(int j=0;j<=11;j++)
        {
            if(day >= monthTotal(year, j) && day < monthTotal(year, j+1))
            {
                month = j+1;
                day = day - monthTotal(year, j);
                cout << year << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << setfill('0') << day+1 << " ";
                switch(g)
                {
                case 0:cout << "Saturday" << endl;break;
                case 1:cout << "Sunday" << endl;break;
                case 2:cout << "Monday" << endl;break;
                case 3:cout << "Tuesday" << endl;break;
                case 4:cout << "Wednesday" << endl;break;
                case 5:cout << "Thursday" << endl;break;
                case 6:cout << "Friday" << endl;break;
                }
            }
        }
        }
    }
    system("PAUSE");
    return 0;
}