/*
郭大卫
1900012995
树的转换
20.11.26
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int h1, h2, t, len;
string str;
void dfs(int d)
{
    h2 = max(h2, d);
    int cnt = 1;
    
    while(t < len)
    {
        if(str[t] == 'd')
        {
            t++;
            dfs(d + cnt);
            cnt++;
        }
        else if(str[t] == 'u')
        {
            t++;
            break;
        }
    }
}

int main()
{
    int cnt = 0;
    while(1)
    {  
        cnt++;
        cin >> str;
        if(str == "#")
            break;

        h1 = 0; h2 = 0;
        len = str.size();
        int tmp = 0;
        for(int i=0; i<len; i++)
        {
            if(str[i] == 'd')
            {
                tmp++;
                h1 = max(h1, tmp);
            }
            else if(str[i] == 'u')
                tmp--;
        }

        t = 0;
        dfs(0);

        cout << "Tree " << cnt << ": " << h1 << " => " << h2 << endl;
    }    
    return 0;
}