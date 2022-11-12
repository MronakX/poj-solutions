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
        int sum=0, maxlength=0;
        char ch, str[1010], strmax[1010];
        while(1)
        {
            ch = cin.get();
            sum ++;
            str[sum] = ch;
            if(ch == ' ' || ch =='.' )
            {
                if(maxlength < sum)
                {
                    maxlength = sum;
                    for(int i=1;i<=sum;i++)
                    {
                        strmax[i] = str[i];
                    }
                    sum = 0;
                }
                else
                {
                    sum = 0;
                }
                
            }
            if(ch == '.')
            {
                for(int i=1;i<maxlength;i++)
                {
                    cout << strmax[i];
                }
                break;
            }
        }
        system("PAUSE");
        return 0;
    }