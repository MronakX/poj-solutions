    /*
    郭大卫
    1900012995
    478-3279
    19.10.23
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int n, cnt;//n为数据个数
        char str[100];//str存储输入数据
        char num[100];//num存储变化后数据
        cin >> n;
        cin.getline(str,100);
        for(int i=0; i<n; i++)
        {
            cnt = 0;//计数归零
            cin.getline(str,100);
            int length = strlen(str);
            for(int j=0; j<length; j++)
            {
                if(str[j] == '-')//无视掉-
                {
                    continue;
                }
                else//存储数字/字母
                {
                    cnt++;
                    num[cnt] = str[j];
                }
                if(cnt == 7)//存储7个字符后结束
                {
                    break;
                } 
            }
            for(int k=1; k<=7; k++)
            {
                if(k == 4)//第四个数字前输出-
                cout << "-";
                if(num[k] == 'A' || num[k] == 'B' || num[k] == 'C')
                cout << 2;
                if(num[k] == 'D' || num[k] == 'E' || num[k] == 'F')
                cout << 3;
                if(num[k] == 'G' || num[k] == 'H' || num[k] == 'I')
                cout << 4;
                if(num[k] == 'J' || num[k] == 'K' || num[k] == 'L')
                cout << 5;  
                if(num[k] == 'M' || num[k] == 'N' || num[k] == 'O')
                cout << 6;
                if(num[k] == 'P' || num[k] == 'R' || num[k] == 'S')
                cout << 7;
                if(num[k] == 'T' || num[k] == 'U' || num[k] == 'V')
                cout << 8;
                if(num[k] == 'W' || num[k] == 'X' || num[k] == 'Y')
                cout << 9;
                if(num[k]>='0' && num[k] <='9')
                cout << num[k];
                if(k == 7)//输出满7个，结束
                cout << endl;
            }

        }
        system("PAUSE");
        return 0;
    }