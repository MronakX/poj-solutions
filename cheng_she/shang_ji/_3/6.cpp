#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    while((cin.peek()) != EOF)
    {
        char str[110] = {};
        int b[110] = {};
        cin.getline(str, 110);
        int len = strlen(str);
        for(int i=0; i<len; i++)//右括号
        {
            if(str[i] == ')')
            {
                b[i] = 1;
                int flag = 1;
                for(int j=i-1;j>=0;j--)
                {
                    if(str[j] == '(' && b[j] == 0)
                    {
                        b[j] = 1;
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    b[i] = 2;//没匹配
                }
            }
        }
        cout << str << endl;
        for(int i=0;i<len;i++)
        {
            if(str[i] == '(' && b[i] == 0)
            {
                cout << "$";
            }
            else if(str[i] == ')' && b[i] == 2)
            {
                cout << "?";
            }
            else
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
    system("pause");
    return 0;
}