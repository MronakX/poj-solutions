#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    double i, a, cond;
    int g = 0;
    int num2, num;
    g = 0;
    cin >> num >> a;
    for(i=0; i<num; i++)
    {
        cin >> num2 >> cond;

        if(cond >= a)
        {
            g = g + 1;
            cout << setfill('0') << setw(3) << num2 <<" "<< fixed << setprecision(1) << cond << endl;
            
        }
    
    }
    if (g == 0)
    {
        cout << "None." << endl;
    }

    system("PAUSE");
    return 0;
}