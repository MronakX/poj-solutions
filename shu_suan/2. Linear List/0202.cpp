/*
郭大卫
1900012995
堆栈基本操作 stack基本操作，注意非法出列判断
20.10.09
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

queue<int> q;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    int n, k, p;
    cin >> n >> k >> p;
    for(int i=1; i<=k; i++)
    {
        q.push(i);
    }
    int cnt = 1;
    while(!q.empty())
    {
        int cd = q.front();
        q.pop();
        if(cnt%n == 0)
        {
            pq.push(cd);
        }
        for(int i=0;i<p && !q.empty();i++)//判断非空很重要!否则re
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        cnt++;
    }
    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    system("pause");
    return 0;
}