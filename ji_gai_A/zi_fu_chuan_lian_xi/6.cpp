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
        char str[1000], num[320][320];
        int row=0, column=0;
        cin.getline(str,1000);
        int length = strlen(str);
        int flag = 0;
        for(int i=0;i<length;i++)
        {
            if(flag == 0 && str[i] >='0' && str[i] <='9')
            {
                flag = 1;
            }
            if(flag == 1)
            {
                if(str[i]>='0' && str[i] <='9')
                {
                    num[row][column] = str[i];
                    column ++;
                }
                else
                {
                    if(column >= 1)
                    {
                        row++;
                        column = 0;
                    }
                } 
            }
        }
        if(str[length-1] <='9' && str[length-1] >='0')
        {
            row++;
        }
        if(flag == 0)
        {
            cout << 0 << endl;
        }
        int cnt[1000]={};
        for(int i=0;i<row;i++)
        {
            int length = strlen(num[i]);
            for(int j=0;j<length;j++)
            {
                cnt[i] += ceil((num[i][j]-'0')* pow(10, length-1-j));
            }
        }
        for(int i=0;i<row;i++)
            for(int j=0;j<row-i;j++)
            {
                if(cnt[j] > cnt[j+1])
                swap(cnt[j],cnt[j+1]);
            }

        for(int i=1;i<=row;i++)
        {
            if(i==1)
            {
                cout << cnt[i];
            }
            else
            {
                cout << ","<<cnt[i];
            }
            
        }
        system("PAUSE");
        return 0;
    }