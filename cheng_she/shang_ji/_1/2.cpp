#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double a, b;
    cin >> n >> a >> b;
    double limit = a / b;
    double ans = 0;
    int ans_above = 0;
    int ans_below = 0;
    for (int i = n; i > 0; i--)
    {
        double below = i;
        for (double j = 0; j < i; j++)
        {
            if (j / below < limit)
            {
                if (j / below > ans)
                {
                    ans = j / below;
                    ans_above = j;
                    ans_below = i;
                }
                
            }
        }
    }
    int k = ans_below;
    for(int i=2;i<=k;i++)
    {
        while(ans_above % i == 0 && ans_below % i == 0)
        {
            ans_above /= i;
            ans_below /= i;
        }
    }
    cout << ans_above << " " << ans_below << endl;
    system("pause");
    return 0;
}