#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct rubb
{
    int x = 0;
    int y = 0;
    int i = 0;
};

bool cmpx(rubb a, rubb b)
{
    return a.x < b.x;
}

bool cmpy(rubb a, rubb b)
{
    return a.y < b.y;
}

int main()
{
    int d, n;
    cin >> d >> n;
    rubb a[22] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].i;
    }
    sort(a, a + n, cmpx);
    int minx = a[0].x, maxx = a[n - 1].x;
    sort(a, a + n, cmpy);
    int miny = a[0].y, maxy = a[n - 1].y;

    int ans = -1;
    int rubbsum = -1;
    for (int i = 0; i < 1025; i++)
    {
        for (int j = 0; j < 1025; j++)
        {
            int tminx = i - d, tmaxx = i + d;
            int tminy = j - d, tmaxy = j + d;
            int tmp = 0;
            int tmprubbsum = 0;
            for (int k = 0; k < n; k++)
            {
                if ((a[k].x >= tminx && a[k].x <= tmaxx) && (a[k].y >= tminy && a[k].y <= tmaxy))
                {
                    tmprubbsum += a[k].i;
                }
            }
            if (tmprubbsum > rubbsum)
            {
                ans = 1;
                rubbsum = tmprubbsum;
            }
            else if (rubbsum == tmprubbsum)
            {
                ans++;
            }
        }
    }
    cout << ans << " " << rubbsum << endl;
    system("pause");
    return 0;
}