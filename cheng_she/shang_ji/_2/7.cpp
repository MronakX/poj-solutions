#include <iostream>
#include <iomanip>
using namespace std;

int pow2[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};

void dfs(int n)
{
    if(n == 1)
    {
        return;
    }
    if(n == 0)
    {
        cout << 0;
        return;
    }
    for(int i=14; i>=0;i--)
    {
        if(pow2[i] <= n)
        {
            if(i == 1)
            {
                cout << 2;
                dfs(i);
            }
            else
            {
                cout << "2(";
                dfs(i);
                cout << ")";
            }
            if(pow2[i] != n)
            {
                cout << "+";
            }
            n -= pow2[i];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    dfs(n);
    system("pause");
    return 0;
}