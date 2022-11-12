#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    while(1)
    {
        int a, num, year=0, month=0, day=0;
        cin >>a;
        num = a%7;
        while(a>365)
        {
            if((year%4 == 0&& year%100!=0)|| (year%400==0)) 
            {
                a=a-365;    
            }
            else
            {
                a = a-365;
            }
        }


        
        if(num ==1)//周日
        if(num ==2)//周一
    }
    system("PAUSE");
    return 0;
}