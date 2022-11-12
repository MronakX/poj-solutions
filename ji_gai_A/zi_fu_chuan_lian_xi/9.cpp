    /*
    郭大卫
    1900012995
    
    19.10.09
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <cstring>
    using namespace std;
    int main()
    {
        int n;
        char str[1000];
        int b[1000]={};
        //0 输出空格，右括号没被遍历过 -1右括号被遍历过,有对应 输出空格 1左括号没有对应 2右括号没有对应
        cin >> n;
        cin.get();
        for(int i=0;i<n;i++)
        {
            memset(b,0,sizeof(b));
            memset(str,'\0',sizeof(str));
            cin.getline(str,1000);
            int length = strlen(str);
            for(int j=length-1; j>=0;j--)//起始点
            {
                if(str[j]=='(')
                {
                    int flag = 0;
                    for(int k=j;k<length;k++)
                    {
                        if(str[k] == ')' && b[k]==0)
                        {
                            b[k] = -1;
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0)
                    {
                        b[j] = 1;
                    }
                }  
            }
            for(int j=0;j<length;j++)
            {
                if(str[j] == ')' && b[j] ==0)
                {
                    b[j] = 2;
                }
            }
            cout << str << endl;
            for(int j=0;j<length;j++)
            {
                if(b[j] == 0 || b[j] == -1)
                {
                    cout << " ";
                }
                if(b[j] == 1)
                {
                    cout << "$";
                }
                if(b[j] == 2)
                {
                    cout << "?";
                }
                if(j==length-1)
                {
                    cout << endl;
                }
            }
        }

            system("PAUSE");
        return 0;
    }