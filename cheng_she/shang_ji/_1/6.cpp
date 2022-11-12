#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                Setbit(origin[i], j, 1);
            }
            if (tmp == 0)
            {
                Setbit(origin[i], j, 0);
            }
        }
    }

    for (int p = 0; p < 64; p++)
    {
        int sum = 0;
        memcpy(map, origin, sizeof(origin));
        pos = p;
        for (int i = 0; i < 5; i++)
        {
            result[i] = pos;
            for (int j = 0; j < 6; j++)
            {
                if (Getbit(pos, j))
                {
                    if (j > 0)
                        Changebit(map[i], j - 1);
                    Changebit(map[i], j);
                    sum++;
                    if (j < 5)
                        Changebit(map[i], j + 1);
                }
            }
            if (i < 4)
            {
                map[i + 1] ^= pos;
            }
            pos = map[i];
        }
        if (map[4] == 0)
        {
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<6;j++)
                {
                    cout << Getbit(result[i], j);
                    if(j<5)
                        cout << " ";
                }
                cout << endl;
            }
        }
    }

    system("pause");
    return 0;
}