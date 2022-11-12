#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int k, i=0;
    cin >>k;
    while(1>0)
    {
        int flag = 2*k;
        int g = 1;
        for(int j=0;j<k;j++)
        {
            
            if((i%(2*k-j)-2*k+flag) <= k)
            {
                break;
                g = 0;
            }
            
        }

        i++;
        if(g = 1)
        {
            cout << i <<endl;
            break;
        }
    }
    system("PAUSE");
    return 0;
}