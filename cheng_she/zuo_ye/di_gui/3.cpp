#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
//高为2^n 最底层宽为2^(n+1)
//maxn = 10;2^11 = 4096
char str[5000][5000] = {};
//把三角形分为上左右三部分，dfs三次，n=1终止
//从左下0,0开始，防止越界
int pow2[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
void dfs(int x, int y, int n)
{
    if (n == 1)
    {
        str[x][y] = str[x + 1][y + 1] = '/';
        str[x + 1][y] = str[x + 2][y] = '_';
        str[x + 2][y + 1] = str[x + 3][y] = '\\';
        str[x][y + 1] = str[x + 3][y + 1] = ' ';
        return;
    }
    dfs(x, y, n - 1);           //左下
    dfs(x + pow2[n], y, n - 1); //右下 x+2^n,y
    dfs(x + pow2[n - 1], y + pow2[n - 1], n - 1);
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        memset(str, 0, sizeof(str));
        dfs(0, 0, n);
        for (int i = pow2[n] - 1; i >= 0; i--)
        {
            for (int j = 0; j < pow2[n + 1]; j++)
            {
                if(str[j][i] == '\000')
                {
                    cout << ' ';
                    continue;
                }
                cout << str[j][i];
            }
            cout << endl;
        }
        cout << endl;
    }
    system("pause");
    return 0;
}