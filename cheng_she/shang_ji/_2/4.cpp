#include <iostream>
#include <iomanip>
using namespace std;
int ans = 0;
void dfs(int x, int y)
{
    for(int i=y;i<=x/i;i++)
    {
        if(x%i == 0)
        {
            ans++;
            dfs(x/i, i);
        }
    }
}

int main()
{
    int n, a;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        ans = 1;
        cin >> a;
        dfs(a,2);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}