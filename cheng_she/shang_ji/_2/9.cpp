#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x)
{
    return (x*x*x*x*x) - 15*(x*x*x*x) + 85*(x*x*x) - 225*(x*x) + 274*x -121;
}

int main()
{
    double eps = 1e-11;
    double L = 1.5;
    double R = 2.4;
    double ans = 0;
    double tmp = 1;
    while(fabs(tmp) > eps)
    {
        double mid = L+(R-L)/2;
        tmp = f(mid);
        if(tmp - 0 > eps)
        {
            L = mid;
        }
        if(tmp - 0 < eps)
        {
            R = mid;
        }
        ans = mid;
    }
    cout << fixed << setprecision(6) << ans << endl;
    //cout << f(1.849016) << endl;
    system("pause");
    return 0;
}