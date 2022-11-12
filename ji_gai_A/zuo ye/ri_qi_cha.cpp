#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    int startYear, startMonth, startDay, endYear, endMonth, endDay, dayYear, dayMonth, dayDay, minus, sum1, sum2;
    cin >> startYear >> startMonth >> startDay >> endYear >> endMonth >> endDay;
    int flag = 0;
    for(int year=startYear;year<=endYear;year++)
    {
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            flag++;
        }
    }
    dayYear = flag*366 + (endYear-startYear-flag)*365;
    //月份差
    switch(startMonth)
        {
        case 1: sum1 = 0;break;
        case 2: sum1 = 31;break;
        case 3: sum1 = 59;break;
        case 4: sum1 = 90;break;
        case 5: sum1 = 120;break;
        case 6: sum1 = 151;break;
        case 7: sum1 = 181;break;
        case 8: sum1 = 212;break;
        case 9: sum1 = 243;break;
        case 10: sum1 = 273;break;
        case 11: sum1 = 304;break;
        case 12: sum1 = 334;break;
        }
        switch(endMonth)
        {
        case 1: sum2 = 0;break;
        case 2: sum2 = 31;break;
        case 3: sum2 = 59;break;
        case 4: sum2 = 90;break;
        case 5: sum2 = 120;break;
        case 6: sum2 = 151;break;
        case 7: sum2 = 181;break;
        case 8: sum2 = 212;break;
        case 9: sum2 = 243;break;
        case 10: sum2 = 273;break;
        case 11: sum2 = 304;break;
        case 12: sum2 = 334;break;
        }
    dayMonth = sum2-sum1;

    //日子差
    dayDay = endDay - startDay;

    minus = dayYear + dayMonth + dayDay;
    cout << minus <<endl;
    system("PAUSE");
    return 0;
}
