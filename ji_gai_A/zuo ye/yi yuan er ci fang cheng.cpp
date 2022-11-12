#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    double a, b, c, x1, x2;
    cin >> a >> b >> c;
    if(pow(b,2)-4*a*c < 0)
    {
        cout << "no solution" <<endl;
    }
    else
    {
    
        x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a); x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
        if (fabs(x1-x2) < 1e-6)
        {
            cout << "x1=x2="<< fixed << setprecision(5) << x1 <<endl;
        }
        else
        { 
            if(x1 > x2)
                cout << "x1=" << fixed << setprecision(5) << x1 <<";x2=" << fixed << setprecision(5) << x2 <<endl;

            else
            {
                cout << "x1=" << fixed << setprecision(5) << x2 <<";x2=" << fixed << setprecision(5) << x1 <<endl;
            
            }
        }
    }    

    system("PAUSE");
    return 0;
}