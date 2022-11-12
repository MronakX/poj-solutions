#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
//2^15 = 32768

void Setbit(int &c, int i, int v)
{
    if (v)
    {
        c |= (1 << i);
    }
    else
    {
        c &= ~(i << i);
    } 
}

int Getbit(int c, int i)
{
    return (c >> i) & 1;
}

void Changebit(int &c, int i)
{
    c ^= (1 << i);
}

int main()
{
    int origin[20] = {};
    int map[20] = {};
    int result[20] = {};
    int pos;
    int n;
    cin >> n;
    int total = 1;
    for (int i = 0; i < n; i++)
    {
        total *= 2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == 'w')
            {
                Setbit(origin[i], j, 1);
            }
            if (tmp == 'y')
            {
                Setbit(origin[i], j, 0);
            }
        }
    }

    int ans = 33000;
    for (int p = 0; p < total; p++)
    {
        int sum = 0;
        memcpy(map, origin, sizeof(origin));
        pos = p;
        for (int i = 0; i < n; i++)
        {
            result[i] = pos;
            for (int j = 0; j < n; j++)
            {
                if (Getbit(pos, j))
                {
                    if (j > 0)
                        Changebit(map[i], j - 1);
                    Changebit(map[i], j);
                    sum++;
                    if (j < n - 1)
                        Changebit(map[i], j + 1);
                }
            }
            if (i < n - 1)
            {
                map[i + 1] ^= pos;
            }
            pos = map[i];
        }
        if (map[n - 1] == 0)
        {
            //cout << sum << endl;
            ans = min(sum, ans);
        }
    }

    if (ans == 33000)
        cout << "inf" << endl;
    else
        cout << ans << endl;
    system("PAUSE");
    return 0;
}