#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct map
{
    int x;
    int y;
};

bool cmp1(map a, map b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    map a[5000] = {};
    int r, c;
    cin >> r >> c;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    //sort(a,a+n,cmp1);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int dx = a[i].x - a[j].x;
            int dy = a[i].y - a[j].y;
            int newx = a[i].x + dx;
            int newy = a[i].y + dy;
            if(newx < 1 || newy < 1 || newx > r || newy > c)
            {
                continue;
            }
            

        }
    }
    system("pause");
    return 0;
}