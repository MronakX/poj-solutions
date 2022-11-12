/*
郭大卫
1900012995
堆栈基本操作 stack基本操作，注意非法出列判断
20.10.09
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>

using namespace std;
int main()
{
    int a[1001] = {};
    int n;
    cin >> n;
    int x;
    int cnt = 0;
    while(cin >> x)
    {
        a[cnt++] = x;
    }
    cnt--;
    int flag = 1;
    int num = 1;
    stack<int> s;
    queue<string> str;
    queue<int> ans; 
    int cur_idx = 0;
        while(cur_idx <= cnt)
    {
        if(a[cur_idx] > n)
        {
            flag = 0;
            break;
        }
        if(num > n+1)
        {
            flag = 0;
            break;
        }
        if(!s.empty() && s.top() == a[cur_idx])
        {
            //cout << "POP " << s.top() << endl;
            str.push("POP");
            ans.push(s.top());
            s.pop();
            cur_idx++;
            continue;
        }
        s.push(num);
        //cout << "PUSH " << num << endl; 
        str.push("PUSH");
        ans.push(num);
        num++;
        
    }
    if(flag)
    {
        while(!str.empty())
        {
            cout << str.front() << " " << ans.front() << endl;
            str.pop();
            ans.pop();
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    system("pause");
    return 0;
}