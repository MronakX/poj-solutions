#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
    int p, e, i, d, j, k;
    int g = 0;
    int num = 0;
    while (1>0)
    {
    
        cin >> p >> e >> i >> d;
        if (p<0 || e<0 || i<0 || d<0)
        {
            break;
        }
        else
        {
            for (j=d+1; j<=21253 + d; j++)
            {   
                
                
                if ((j-p)%23 == 0 && (j-e)%28 == 0 && (j-i)%33 == 0)
                {
                    
                    num++;
                    cout << "Case "<< num <<": the next triple peak occurs in "<< j-d << " days."<< endl;
                    break;
                }
                
                
            
            }       
        } 
    }
    system("PAUSE");
    return 0;
}