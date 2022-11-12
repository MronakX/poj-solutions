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
        char str1[100], str2[100], str3[100], str4[100];
        int num[30]={};
        cin.getline(str1,100);   
        cin.getline(str2,100);   
        cin.getline(str3,100);   
        cin.getline(str4,100);   
        int length1 = strlen(str1);
        int length2 = strlen(str2);
        int length3 = strlen(str3);
        int length4 = strlen(str4);

        for(int i=0;i<length1;i++)
        {
            if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                num[str1[i]-64]++;
            }
        }
        for(int i=0;i<length2;i++)
        {
            if(str2[i] >= 'A' && str2[i] <= 'Z')
            {
                num[str2[i]-64]++;
            }
        }
        for(int i=0;i<length3;i++)
        {
            if(str3[i] >= 'A' && str3[i] <= 'Z')
            {
                num[str3[i]-64]++;
            }
        }
        for(int i=0;i<length4;i++)
        {
            if(str4[i] >= 'A' && str4[i] <= 'Z')
            {
                num[str4[i]-64]++;
            }
        }

        int maxheight = num[1];
        for(int i=2;i<=26;i++)
        {
            maxheight = max(maxheight, num[i]);
        }
        
        int maxlength;
        for(int i=maxheight;i>0;i--)
        {
            for(int j=1;j<=26;j++)
            {
                if(num[j] >= i)
                {
                    maxlength = j;
                }
            }
            for(int j=1;j<=26;j++)
            {
                if(j == 1 && num[j]>= i)
                {
                    cout << "*";
                }
                if(j==1 && num[j]<i)
                {
                    cout << " ";
                }
                if(j!=1 && num[j] >= i)
                {
                    cout << " *";
                }
                if(j!=1 && num[j] < i)
                {
                    cout << "  ";
                }
                if(j == maxlength)
                {
                    cout << endl;
                    break;
                }
            }
        }


        cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
        system("PAUSE");
        return 0;
    }