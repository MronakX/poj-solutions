#include <iostream>
#include <iomanip>
using namespace std;

long long ans = 0;
long long a[200010] = {};
long long tmp[200010] = {};
void Merge(long long s, long long m , long long e)
{
    long long pb = 0;
    long long p1 = s, p2 = m+1;
    while(p1 <= m && p2 <= e)
    {
        if(a[p1] <= 2*a[p2])
            p1++;
        else
        {
            p2++;
            ans += m- p1 + 1;
        
        }
    }
    p1 = s;
    p2 = m+1;
    while(p1 <= m && p2 <= e)
    {
        if(a[p1] <= a[p2])
            tmp[pb++] = a[p1++];
        else
        {
            tmp[pb++] = a[p2++];
        
        }
    }
    while(p1 <= m)
        tmp[pb++] = a[p1++];
    while(p2 <= e)
        tmp[pb++] = a[p2++];
    for(int i=0;i<e-s+1;i++)
    {
        a[s+i] = tmp[i];
    }
}

void MergeSortAndCount(long long s, long long e)
{  
    if(s < e)
    {
        long long m = s+(e-s)/2;
        MergeSortAndCount(s, m);
        MergeSortAndCount(m+1, e);
        Merge(s, m, e);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    MergeSortAndCount(0, n-1);
    cout << ans << endl;
    system("pause");
    return 0;
}