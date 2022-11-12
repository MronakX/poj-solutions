/*
郭大卫
1900012995
表达式·表达式树·表达式求值 
20.11.28
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;

struct point
{
    int x, y, z;
    int num;
}a[20];

struct dist
{
    point a, b;
    int num1, num2;
    double dis;
};

bool cmp(dist a, dist b)
{
    if(a.dis == b.dis)
    {
        if(a.num1 == b.num1)
            return a.num2 < b.num2;
        return a.num1 < b.num1;
    }   
    return a.dis > b.dis;
}

int main()
{
    dist d[1000];
    int n;  
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].num = i;
    }
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            d[cnt].a = a[i];
            d[cnt].b = a[j];
            int dx = a[i].x - a[j].x;
            int dy = a[i].y - a[j].y;
            int dz = a[i].z - a[j].z;
            double dis = dx*dx + dy*dy + dz*dz;
            dis = sqrt(dis);
            d[cnt].dis = dis;
            cnt++;
            d[cnt].num1 = min(a[i].num, a[j].num);
            d[cnt].num2 = max(a[i].num, a[j].num); 
        }
    }

    sort(d,d+cnt,cmp);
    for(int i=0; i<cnt; i++)
    {
        cout << "(" << d[i].a.x << "," << d[i].a.y << "," << d[i].a.z << ")";
        cout << "-";
        cout << "(" << d[i].b.x << "," << d[i].b.y << "," << d[i].b.z << ")";
        cout << fixed << setprecision(2) << "=" << d[i].dis << endl; 
    }
    system("pause");
    return 0;
}