#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n1, n2, n3, n4, n5, k;
    cin >> k >> n1 >> n2 >> n3 >> n4 >> n5;
    double x1, x2, x3 ,x4 ,x5;
    for (int i=1; i<=k;i++)//i为高度
    {
        x5 = n1*n2*n3*n4*i*(1- 1/n1 + 1/(n1*n2) - 1/(n1*n2*n3) + 1/(n1*n2*n3*n4));
    }

    system("PAUSE");
    return 0;
}