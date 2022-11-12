#include <iostream>
#include <iomanip>
using namespace std;

int dfs(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    return dfs(b, a%b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    if(a == b)
    {
        cout << a << endl;
    }
    else if(a > b)
    {
        cout << dfs(a, b) << endl;
    }
    else
    {
        cout << dfs(b, a) << endl;
    }
    
    system("pause");
    return 0;
}