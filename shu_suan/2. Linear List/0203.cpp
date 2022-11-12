/*
郭大卫
1900012995
堆栈基本操作 stack基本操作，注意非法出列判断
20.10.09
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string stra, strb;
    while(cin >> stra >> strb)
    {
        int lena = stra.size();
        int pos = 0;
        int maxas = stra[0];
        for(int i = 1; i<lena; i++)
        {
            if(stra[i] > maxas)
            {
                pos = i;
                maxas = stra[i];
            }
        }
        string tmp;
        tmp = stra.substr(0, pos+1) + strb + stra.substr(pos+1, lena-pos);
        cout << tmp << endl;
    }    
    system("pause");
    return 0;
}