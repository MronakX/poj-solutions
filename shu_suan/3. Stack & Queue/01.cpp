/*
郭大卫
1900012995
滑动窗口（经典） 构造单调队列
20.10.09
*/

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int a[1000100] = {};

int main()
{
    deque<int> q1;
    deque<int> q2;
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    queue<int> ans1;
    queue<int> ans2;
    for(int i=0; i<n;i++)
    {
        int cur = a[i];
        while(!q1.empty() && q1.back() < cur)
        {
            q1.pop_back();
        }
        q1.push_back(cur);
        while(!q2.empty() && q2.back() > cur)
        {
            q2.pop_back();
        }
        q2.push_back(cur);
        
        if(i > k-1)
        {
            if(q1.front() == a[i-k])
                q1.pop_front();
            if(q2.front() == a[i-k])
                q2.pop_front();
        }
        if(i >= k-1)
        {
            ans1.push(q1.front());
            ans2.push(q2.front());
        }
    }
    cout << ans2.front();
    ans2.pop();
    while(!ans2.empty())
    {
        cout << " " << ans2.front();
        ans2.pop();
    }
    cout << endl;

    cout << ans1.front();
    ans1.pop();
    while(!ans1.empty())
    {
        cout << " " << ans1.front();
        ans1.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}