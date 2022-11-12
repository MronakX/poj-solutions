#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int reverse(int i)
{
    int tmp = 0;
    while (i)
    {
        tmp = tmp*10 + i%10;
        i /= 10;
    }
    return tmp;
}

int main()
{
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
    {
        int k = sqrt(i);
        int flag = 0;
        for (int j = 2; j <= k; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            int rev = reverse(i);
            int k2 = sqrt(rev);
            int flag2 = 0;
            for(int j=2;j<=k2;j++)
            {
                if(rev % j == 0)
                {
                    flag2 = 1;
                    break;
                }
            }
            if(!flag2 && ans == 0)
            {
                cout << i;
                ans ++;
            }
            else if(!flag2 && ans)
            {
                cout << "," << i;
                ans++;
            }
        }
    }
    if(!ans)
    {
        cout << "No" << endl;
    }
    system("pause");
    return 0;
}