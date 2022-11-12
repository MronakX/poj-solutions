#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int n, sum, sum2,a;
    cin >> n;
    for (a = 220; a <= n; a++)
    {
        sum = 1;
        sum2 = 1;
        for(int i = 2;i <= sqrt(a);i++)
        {
            if(a%i == 0)
            {
            sum = sum + i + a/i;//a的公因数之和
            }
        }
        if(sum > a && sum < n)
        {
            for (int j = 2;j<= sqrt(sum);j++)
            {
                if(sum%j==0)
                {
                    sum2 = sum2 + j + sum/j;
                }
            }
        
        if(sum2 == a)
        cout << a << " " << sum << endl;
        }    
    
    }
    system("PAUSE");
    return 0;
}