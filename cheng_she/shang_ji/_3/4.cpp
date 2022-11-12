#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int trans(int x, int B)
{
    int ans = 0;
    int tmp = x;
    int cnt = 0;
    int flag = 0;
    while(tmp > 0)
    {
        int plus = tmp%10;
        if(plus >= B)
        {
            flag = 1;
            break;
        }
        plus = plus * pow(B, cnt);
        cnt++;
        ans += plus;
        tmp/= 10;
    }
    if(flag)
    {
        return -1;
    }
    return ans;
}

int main()
{
    int p, q, r;
    int pp, qq, rr;
    cin >> p >> q >> r;
    int flag = 0;
    for(int i=3;i<=16;i++)
    {
        pp = trans(p, i);
        qq = trans(q, i);
        rr = trans(r, i);
        if(pp == -1 || qq == -1 || rr == -1)
        {
            continue;
        }
        //cout << i << endl;
        //cout << pp << " " << qq << " " << rr << endl;
        if(pp*qq == rr)
        {
            flag = 1;
            cout << i << endl;
            break;
        }
    }
    if(!flag)
    {
        cout << 0 << endl;
    }
    system("pause");
    return 0;
}