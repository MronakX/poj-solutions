/*
郭大卫
1900012995
中缀表达式 
20.10.09
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>

using namespace std;

bool check_prior(char a, char b)//a<=b true
{
    if(a == '+' || a == '-')
        return true;
    else
    {
        if(b == '+' || b == '-')
            return false;
        else
            return true;
    }
    
}


int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        stack<char> s;
        vector<char> post;
        char str[1000] = {};
        cin.getline(str, 900);
        int cnt = 0;
        while(str[cnt] != 0)
        {
            if(str[cnt] <= '9' && str[cnt] >= '0')
            {
                post.push_back(str[cnt]);
                cnt++;
                continue;
            }
            else
            {
                post.push_back(' ');
            }
            
            if(str[cnt] == '(')
            {
                s.push(str[cnt]);
                cnt++;
            }
            else if(str[cnt] != ')')
            {
                while(1)
                {
                    if(!s.empty() && s.top() != '(' && check_prior(str[cnt], s.top()))
                    {
                        post.push_back(s.top());
                        s.pop();
                    }
                    else
                    {
                        s.push(str[cnt]);
                        cnt++;
                        break;
                    }
                }
            }
            else
            {
                while(s.top() != '(')
                {
                    post.push_back(s.top());
                    s.pop();
                }
                s.pop();
                cnt++;
            }
        }
        while(!s.empty())
        {
            post.push_back(s.top());
            s.pop();
        }

        stack<int> ans;
        for(auto i = post.begin(); i!=post.end(); i++)
        {
            int number = 0;
            int op1, op2;
            bool flag = 0;
            while(i != post.end() && *i <= '9' && *i >= '0')
            {
                flag = 1;
                number *= 10;
                number += (*i-'0');
                i++;
            }
            if(flag)
            {
                i--;
                ans.push(number);
                continue;
            }

            if(*i == '+')
            {
                op1 = ans.top();
                ans.pop();
                op2 = ans.top();
                ans.pop();
                ans.push(op2 + op1);
            }
            else if(*i == '-')
            {
                op1 = ans.top();
                ans.pop();
                op2 = ans.top();
                ans.pop();
                ans.push(op2 - op1);
            }
            else if(*i == '*')
            {
                op1 = ans.top();
                ans.pop();
                op2 = ans.top();
                ans.pop();
                ans.push(op2 * op1);
            }
            else if(*i == '/')
            {
                op1 = ans.top();
                ans.pop();
                op2 = ans.top();
                ans.pop();
                ans.push(op2 / op1);
            }
        }
        cout << ans.top() << endl;
    }
    system("pause");
    return 0;
}