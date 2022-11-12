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
        int n;
        char str[1020][20], str2[1020][20], temp[1020][20];
        cin >> n;
        cin.get();
        for(int i=1;i<=n;i++)
        {
            cin.getline(str[i],1000);
            int length = strlen(str[i]);
            for(int j=0;j<length;j++)
            {
                if(str[i][j] == 'z')
                {
                    str[i][j] = 'c';
                }
                else if(str[i][j] == 'y')
                {
                    str[i][j] = 'b';
                }
                else if(str[i][j] == 'x')
                {
                    str[i][j] = 'a';
                }
                else if(str[i][j] == 'Z')
                {
                    str[i][j] = 'C';
                }
                else if(str[i][j] == 'Y')
                {
                    str[i][j] = 'B';
                }
                else if(str[i][j] == 'X')
                {
                    str[i][j] = 'A';
                }
                else{
                    str[i][j] = str[i][j] + 3;
                }
            }
            for(int j=0;j<length;j++)
            {
                str2[i][j] = str[i][length-j-1];
            }
            for(int j=0;j<length;j++)
            {
                if(str2[i][j] >='a' && str2[i][j] <= 'z')
                {
                    str2[i][j] = str2[i][j] - 32;
                }
                else
                {
                    str2[i][j] = str2[i][j] + 32;
                }
                
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i;j++)
            {
                if(strcmp(str2[j],str2[j+1])>0)
                {
                    strcpy(temp[j], str2[j]);
                    strcpy(str2[j], str2[j+1]);
                    strcpy(str2[j+1], temp[j]);
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            int j =0;
            int length = strlen(str2[i]);
            for(int j=0;j<length;j++)
            {
                cout << str2[i][j];
                if(j==length-1)
                {
                    cout << endl;
                }
            }
        }
        system("PAUSE");
        return 0;
    }