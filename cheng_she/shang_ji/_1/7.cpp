#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int next = 0;
    for(int a=1;;a++)
    {
        int tmp = a;
        int flag = 1;
        for(int j=0;j<n-1;j++)
        {
            int thisd = n*tmp + 1;
            if(thisd % (n-1) != 0)
            {
                flag = 0;
                break;
            }
            tmp = thisd/(n-1);
        }
        if(flag == 1)
        {
            cout << tmp*n+1 << endl;
            break;
        }
    }
    
    system("pause");
    return 0;
}