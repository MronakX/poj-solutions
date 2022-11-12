#include <iostream>
#include <iomanip>
using namespace std;

int apple(int m, int n)
{
    if(m < 0 || n <= 0)
    {
        return 0;
    }
    if(n == 1 || m == 0 )
    {
        return 1;
    }
    return apple(m,n-1) + apple(m-n,n);
    
}

int main()
{
    int m, n, t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> m >> n;
        cout << apple(m,n) << endl;
    }
    system("pause");
    return 0;
}