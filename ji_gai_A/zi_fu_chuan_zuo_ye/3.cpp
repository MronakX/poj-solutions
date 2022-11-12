    /*
    郭大卫
    1900012995
    验证字串
    19.10.23
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        char str1[120], str2[120];
        cin.getline(str1,119);
        cin.getline(str2,119);
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        int flag, g=0;//flag, g 用于标记
        if(length1 <= length2)
        {
            for(int i=0; i<=length2-length1; i++)//str2的起始点为i
            {
                flag = 0;//标记归零
                for(int j=0; j<length1; j++)//起始点右数length1个字符
                {
                    if(str1[j] != str2[j+i])//不匹配，则跳出，以下一个为起始点
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)//如果length1个字符全部相等，输出。
                {
                    cout << str1 << " is substring of " << str2 <<endl;
                    g = 1;//有解置为1
                    break;
                }
            }
        }
        else//2是1的字串，同理
        {
            for(int i=0; i<=length1 - length2; i++)
            {
                flag = 0;
                for(int j=0; j<length2; j++)
                {
                    if(str2[j] != str1[j+i])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0)
                {
                    cout << str2 << " is substring of " << str1 <<endl;
                    g = 1;
                    break; 
                }
            }
        }
        if(g == 0)//无解，输出结果
        {
            cout << "No substring" << endl;
        }
        system("PAUSE");
        return 0;
    }