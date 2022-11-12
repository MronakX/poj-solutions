    /*
    郭大卫
    1900012995
    
    19.10.09
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        char str[1000];
        cin.getline(str,1000);
        int length = strlen(str);
        for(int i=2;i<=length;i++)//changdu
        {
            int j;
            for(j=0;j<length;j++)//起始位置
            {
                int flag = 1;  
                for(int k=j;k<j+i;k++)
                {
                    if(str[k] != str[2*j+i-1-k])
                    {
                        flag = 0;
                        break;;
                    }
                }
                if(flag == 1)
                {
                for(int k=j;k<j+i;k++)
                {
                    cout << str[k];
                    if(k==j+i-1)
                    {
                        cout << endl;
                    }
                }
                }
                
            }
            
        }
        system("PAUSE");
        return 0;
    }