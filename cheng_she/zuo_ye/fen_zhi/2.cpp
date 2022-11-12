#include <iostream>
#include <iomanip>
using namespace std;

long long ans = 0;

void Merge(long long a[], long long s, long long m , long long e, long long tmp[])
{
    long long pb = 0;
    long long p1 = s, p2 = m+1;
    while(p1 <= m && p2 <= e)
    {
        if(a[p1] < a[p2])
            tmp[pb++] = a[p1++];
        else
        {
            tmp[pb++] = a[p2++];
            ans += m- p1 + 1;
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

void MergeSortAndCount(long long a[], long long s, long long e, long long tmp[])
{  
    if(s < e)
    {
        long long m = s+(e-s)/2;
        MergeSortAndCount(a, s, m, tmp);
        MergeSortAndCount(a, m+1, e, tmp);
        Merge(a, s, m, e, tmp);
    }
}

int main()
{
    long long a[100010] = {};
    long long tmp[100010] = {};
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    MergeSortAndCount(a, 0, n-1, tmp);
    cout << ans << endl;
    system("pause");
    return 0;
}