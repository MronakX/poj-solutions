#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
int a, b, c, A, B, C;
for (a = 0; a <= 2; a ++)
for (b = 0; b <= 2; b ++)
for (c = 0; c <=2; c ++)
{
A = (b > a) + (a == c) ;
B = (a > b) + (a > c );
C = (c > b) + (b > a);
if ((A + a) == (B + b) && (B + b) == (C + c))
for (int i = 2; i >= 0; i--) //饭量大的排在前面
{
if (a == i) cout << 'A' << endl;
if (b == i) cout << 'B' << endl;
if (c == i) cout << 'C' << endl;
}
} 
    system("PAUSE");
    return 0;
}