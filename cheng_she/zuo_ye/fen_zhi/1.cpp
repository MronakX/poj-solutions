#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void arrangeRight(int a[], int s, int e, int k)
{
    int i = s, j = e;
    int key = a[s];
    while (i != j)
    {
        while ((i < j) && a[j] >= key)
        {
            j--;
        }
        swap(a[i], a[j]);
        while ((i < j) && a[i] <= key)
        {
            ++i;
        }
        swap(a[i], a[j]);
    }

    int num = e - i + 1;
    if (num == k)
        return;
    else if (num > k)
        arrangeRight(a, i + 1, e, k);
    else
        arrangeRight(a, s, i - 1, k - num);
}

int main()
{
    int n, k;
    cin >> n;
    int a[100010] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    arrangeRight(a, 0, n - 1, k);
    sort(a + n - k, a + n);
    for (int i = n - 1; i >= n - k; i--)
    {
        cout << a[i] << endl;
    }
    system("pause");
    return 0;
}