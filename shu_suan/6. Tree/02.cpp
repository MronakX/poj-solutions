/*
郭大卫
1900012995
发现它抓住它 并查集 scanf/printf
20.11.25
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int f[100010] = {};
int r[100010] = {};

int findPC(int n)
{
    if(n == f[n])
        return n;
    int tmp;
    tmp = findPC(f[n]);
    r[n] = (r[n] + r[f[n]]) % 2;
    f[n] = tmp;
    return f[n];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i=1; i<=n;i++)
        {
            f[i] = i;
            r[i] = 0;
        }
        while(m--)
        {
            char ch;
            int a, b, fa, fb;
            getchar();
            scanf("%c%d%d", &ch, &a, &b);
            fa = findPC(a);
            fb = findPC(b);
            if(ch == 'D')
            {
                f[fa] = fb;
                if(r[b] == 1)
                    r[fa] = r[a];
                else
                    r[fa] = 1-r[a];
            }
            else if(ch == 'A')
            {
                if(fa != fb)
                    printf("Not sure yet.\n");
                else if(r[a] == r[b])
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");  
            }
        }
    }   
    return 0;
}