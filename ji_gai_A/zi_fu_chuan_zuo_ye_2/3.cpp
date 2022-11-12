/*
郭大卫
1900012995
土豪的月收入
19.10.30
*/

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <cstring>
    using namespace std;
    char str1[220], str2[220];//str1存储结果，str为新的加数
    int num1[220], num2[220], sum[220];//num1，num2, sum为中间值
    void opplus()//大整数加法
    {
        memset(str2,0,sizeof(str2));//每次加法前，数组清零
        memset(sum,0,sizeof(sum));
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        cin >> str2;//输入加数
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int i, j =0;
        for(i=len1-1; i>=0; i--)
        {
            num1[j] =  str1[i] - '0';
            j++;
        }
        j=0;
        for(int i=len2-1; i>=0; i--)
        {
            num2[j] = str2[i]-'0';
            j++;
        }
        for(int i=0; i<220; i++)
        {
            sum[i] += num1[i] + num2[i];
            if(sum[i] >=10)
            {
                sum[i] -= 10;
                sum[i+1] ++;
            }
        }
        i=219,j=0;
        while(sum[i] == 0)
        {
            i--;
        }
        for(; i>=0; i--)//每次都把sum的值存入str1，用于下一次opplus
        {
            str1[j] = char(sum[i])+48;
            j++;
        }
        
    }
    int main()
    {
        int n;
        cin >> n;
        cin >> str1;//输入第一个数字
        for(int i=1;i<n;i++)//加n-1次
        {
            opplus();   
        }
        cout << str1 << endl;//输出最终结果
        system("pause");
        return 0;
    }