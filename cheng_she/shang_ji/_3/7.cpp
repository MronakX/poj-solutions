#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
//n<=7
//长 宽为3^(n-1)
int pow_3[8] = {1, 3, 9, 27, 81, 243, 729, 729*3};
char a[4000][4000] = {};

void dfs(int x, int y, int n)//左上角为（0,0）
{
    if(n == 0)
    {
        a[x][y] = 'X';
        return;
    }
    if(n == 1)
    {
        a[x][y] = a[x+2][y] = a[x+1][y+1] = a[x][y+2] = a[x+2][y+2] = 'X';
        a[x+1][y] = a[x][y+1] = a[x+2][y+1] = a[x+1][y+2] = ' ';
        return;
    }
    dfs(x, y, n-1);
    dfs(x+2*pow_3[n-1], y, n-1);
    dfs(x, y+2*pow_3[n-1], n-1);
    dfs(x+pow_3[n-1], y+pow_3[n-1], n-1);
    dfs(x+2*pow_3[n-1], y+2*pow_3[n-1], n-1);
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        memset(a, ' ', sizeof(a));
        if (n == -1)
            break;

        dfs(0, 0, n);
        for(int y=0;y<pow_3[n-1];y++)
        {
            for(int x=0;x<pow_3[n-1];x++)
            {
                cout << a[x][y];
            }
            cout << endl;
        }
        cout << "-" << endl;
    }
    system("pause");
    return 0;
}