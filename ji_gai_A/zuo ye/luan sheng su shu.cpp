#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    
    int n, battery, max, temp, sum=0;
    double time;
    while(cin >> n >> max);
    {
    for (int i=0;i<n;i++)
    {
        cin >> battery;
        if (battery > max)
        {
            temp = max;
            max = battery;
            battery = temp;
        }
        sum = sum + battery;
        
    }
    if (max <= sum )
    {
        time = (sum + max)/2.0;
    }
    else
        time = sum;

        cout << fixed << setprecision(1) << time << endl;
    }
    system("PAUSE");
    return 0;
}