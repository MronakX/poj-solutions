    /*
    郭大卫
    1900012995
    判断字符串是否为回文	
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
        int flag = 1;//flag标记是否回文
        cin.getline(str1,110);//str1 为输入数组
        int length = strlen(str1);
        for(int i=length-1;i >= 0;i--)
        {
            if(str1[i] != str1[length-1 - i])//两侧向里进行比对，如果有不回文的地方，标记0
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            cout << "yes" << endl;
        }
        else 
        {
            cout << "no" << endl;
        }
        

        system("PAUSE");
        return 0;
    }