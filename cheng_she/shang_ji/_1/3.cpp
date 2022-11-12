#include <iostream>
#include <iomanip>
using namespace std;

struct train
{
    int up;
    int down;
    int total = 0;
};

int main()
{
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    train tr[20] = {};
    tr[1].up = a;
    tr[1].down = 0;
    tr[1].total = a;
    tr[n].down = m;
    int up2 = 0;
    int down2 = 0;
    for(int i=1;i<=5000;i++)
    {
        tr[2].up = i;
        tr[2].down = i;
        tr[2].total = a;
        for(int j = 3;j<n;j++)
        {
            tr[j].up = tr[j-1].up + tr[j-2].up;
            tr[j].down = tr[j-1].up;
            tr[j].total = tr[j-1].total + tr[j].up - tr[j].down;
        }
        if(tr[n-1].total == m)
        {
            up2 = i;
            down2 = i;
            break;
        }
    }
    tr[2].up = up2;
    tr[2].down = down2;
    tr[2].total = a;
    for(int j=3;j<=x;j++)
    {
        tr[j].up = tr[j-1].up + tr[j-2].up;
        tr[j].down = tr[j-1].up;
        tr[j].total = tr[j-1].total + tr[j].up - tr[j].down;
    }
    cout << tr[x].total << endl;
    system("pause");
    return 0;
}