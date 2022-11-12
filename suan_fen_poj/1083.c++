#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int cnt[220] = {};
        for(int i=0; i<n; i++)
        {
            int st, ed;
            cin >> st >> ed;
            if(st > ed)
                swap(st, ed);

            if(st%2 == 1)
                st = (st+1)/2;
            else
                st = st/2;

            if(ed%2 == 1)
                ed = (ed+1)/2;
            else    
                ed = ed/2;

            for(int j = st; j <= ed; j++)
            {
                cnt[j]++;
            }
        }

        int ans = -1;
        for(int j=1; j<=200; j++)
        {
            ans = max(cnt[j], ans);
        }

        cout << ans * 10 << endl;
    }
    system("pause");
    return 0;
}