/*
郭大卫
1900012995
神奇的幻方 模拟
20.09.29
*/

#include <iostream>
using namespace std;

int a[50][50] = {};

int main()
{
    int n;
    cin >> n;
    int M = 2*n-1;//3-->5
    a[0][n-1] = 1;
    int lastR = 0;
    int lastC = n-1;
    for(int i=2;i<=M*M;i++)
    {
        //注意判定顺序
        if(lastR == 0 && lastC != M-1)
        {
            a[M-1][lastC + 1] = i;
            lastR = M-1;
            lastC = lastC + 1;
            continue;
        }
        else if(lastR != 0 && lastC == M-1)
        {
            a[lastR - 1][0] = i;
            lastR = lastR-1;
            lastC = 0;
            continue;
        }
        else if(lastR == 0 && lastC == M-1)
        {
            a[lastR + 1][lastC] = i;
            lastR = lastR + 1;
            lastC = lastC;
            continue;
        }
        else if(a[lastR - 1][lastC + 1] != 0)
        {
            a[lastR + 1][lastC] = i;
            lastR = lastR + 1;
            lastC = lastC;
            continue;
        }
        else
        {
            a[lastR - 1][lastC + 1] = i;
            lastR = lastR - 1;
            lastC = lastC + 1;
        }
    }
    for(int i=0; i<M;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}