#include <iostream>
#include <iomanip>
using namespace std;
int a[1010] = {};
int b[1010] = {};

void bigPow2(int n)
{
    if(b == 0) return;
    if(b % 2 == 1)
    {
        bigPow2(n-1);
    }
    else
    {
        bigPow2(n/2);
    }
    for(int i=0;i<500;i++)
    {
        for(int j=0;j<500;j++)
        {
            
        }
    }
    
}

int main()
{
    int n;
    cin >> n;

    system("pause");
    return 0;
}