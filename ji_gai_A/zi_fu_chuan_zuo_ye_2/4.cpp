/*
郭大卫
1900012995
计算2的N次方
19.10.30
*/

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <cstring>
    using namespace std;
    char str[200]={'1'};//str存数据，初始计为一个1
    int num[200]={};//num存储中间值
    void erbei()//用于乘法
    {
        memset(num, 0, sizeof(num));//每次清零
        int len = strlen(str);
        int j = 0;
        for(int i=len-1; i>=0; i--)//字符转整数
        {
            num[j++] = str[i] - '0';
        }
        j = 0;
        for(int i=0; i<len; i++)
        {
            num[i] = 2 * num[i];
        }
        for(int i=0; i<2*len; i++)
        {
            if(num[i] >= 10)//进位
            {
                num[i+1] += num[i] / 10;
                num[i] = num[i] % 10;
            }
        }
        int i = 2 * len - 1;
        j = 0;
        while(num[i] == 0)//去掉前导零
        {
            i--;
        }
        for(; i>=0; i--)//存进str
        {
            str[j++] = char(num[i]) + 48;
        }

    }
    int main()
    {
        int n;
        cin >> n;
        
        for(int i=1; i<=n; i++)//做n次乘法，如果n为0，不进行乘法，直接输出2^0 = 1
        {
            erbei();
        }
        cout << str << endl;
        system("pause");
        return 0;
    }