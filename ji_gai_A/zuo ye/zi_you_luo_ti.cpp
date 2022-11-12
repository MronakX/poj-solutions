#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    double max, num,  sum=0, bounce;
    cin >> max >> num;
    sum = max;
    if(num==1)
    {

        bounce = max/2;
    }
    for(double i=2;i<=num;i++)
    {   
        max = max/2;
        sum = sum + max + max;
        bounce = max/2;
    }
    cout << fixed << setprecision(4) << sum << " " << bounce <<endl; 
    system("PAUSE");
    return 0;
}