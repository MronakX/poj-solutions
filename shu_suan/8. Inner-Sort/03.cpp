/*
郭大卫
1900012995
表达式·表达式树·表达式求值 
20.11.28
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;

struct DNA
{
    string str;
    int num = 0;
    int input;
    void get_num()
    {
        int len = str.size();
        for(int i=0; i<len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(str[i] > str[j])
                    num++;
            }
        }
    }
};

bool cmp(DNA a, DNA b)
{
    if(a.num == b.num)
        return a.input < b.input;
    return a.num < b.num;
}

DNA a[200];

int main()
{
    int m, n;
    cin >> m >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].str;
        a[i].input = i;
        a[i].get_num();
    }
    sort(a, a+n, cmp);
    for(int i=0;i<n;i++)
    {
        cout << a[i].str << endl;
    }
    system("pause");
    return 0;
}