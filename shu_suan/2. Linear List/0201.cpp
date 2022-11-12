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

bool check(string src, string des)
{
    int len1 = src.length();
    int len2 = des.length();
    if(abs(len1 - len2) > 1)
        return false;
    int flag = 0;
    if(len1 == len2)
    {
        for(int i=0;i<len1;i++)
        {
            if(src[i] != des[i])
            {
                flag++;
            }
        }
        if(flag > 1)
        {
            return false;
        }
        return true;
    }
    else if(len1 > len2)//src > des, 删除src len1中一个字母
    {
        for(int i=0;i<len1;i++)
        {
            string tmp = src.substr(0, i) + src.substr(i+1, len1 - i - 1);
            if(tmp == des) 
                return true;
        }
    }
    else if(len1 < len2)
    {
        for(int i=0;i<len2;i++)
        {
            string tmp = des.substr(0, i) + des.substr(i+1, len2 - i - 1);
            if(tmp == src) 
                return true;
        }
    }
    return false;
}

int main()
{
    vector<string> v;
    while(1)
    {
        string str;
        cin >> str;
        if(str == "#")
            break;
        v.push_back(str);
    }
    
    while(1)
    {
        string src;
        cin >> src;
        if(src == "#")
            break;
        auto it = find(v.begin(), v.end(), src);
        if(it != v.end())
            cout << src << " is correct" << endl;
        else
        {
            int flag = 0;
            cout << src << ":";
            for(auto i = v.begin(); i!=v.end();i++)
            {
                auto des = *i;
                if(check(src, des))
                {
                    cout << " " << des;
                    flag = 1;
                }   
            }
            cout << endl;
        }
        
    }
    system("pause");
    return 0;
}