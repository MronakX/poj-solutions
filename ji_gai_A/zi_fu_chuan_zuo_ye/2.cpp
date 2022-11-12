    /*
    郭大卫
    1900012995
    习题(12-5) 行程长度编码
    19.10.23
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        char str[1200];
        int sum = 1;//计数器
        cin.getline(str,1100);
        int length = strlen(str);
        for(int i=1; i<=length; i++)
        {
            if(str[i] == str[i-1] || str[i] == str[i-1]+32 || str[i] == str[i-1] - 32)//如果某个字符与前一个一样，或者是大/小写，计数++
            {
                sum ++;
            }
            else//不一样时，开始输出
            {
                if(str[i-1] >= 'a')
                {
                cout << "(" << char(str[i-1]-32) << "," << sum << ")" ;
                sum = 1; 
                }
                else
                {
                cout << "(" << char(str[i-1]) << "," << sum << ")" ;
                sum = 1;
                }
            }
        }
        system("PAUSE");
        return 0;
    }