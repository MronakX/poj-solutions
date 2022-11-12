#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    long n, month1, day1, initial, month2, day2, sum1, sum2, minus;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> month1 >> day1 >> initial >> month2 >> day2;
        switch(month1)
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
        switch(month2)
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
        sum1 += day1;
        sum2 += day2;

        minus = sum2 - sum1;

        for(int i=0;i<minus;i++)
        {
            initial *= 2;
        }
        cout << initial<<endl;

    }
    system("PAUSE");
    return 0;
}