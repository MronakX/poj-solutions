    /*
    郭大卫
    1900012995
    校门外的树
    19.10.09
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int day;
        int a[20][20]= {}, b[20][20] = {};
        cin >> a[5][5] >> day;
        for(int k=0;k<day;k++)
        {
            for(int i=1;i<=9;i++)
            {
                for(int j=1;j<=9;j++)
                {
                    if(a[i][j] != 0)
                    {
                        b[i][j] += 2*a[i][j];
                        b[i-1][j] += a[i][j];
                        b[i+1][j] += a[i][j];
                        b[i-1][j+1] += a[i][j];
                        b[i+1][j+1] += a[i][j];
                        b[i-1][j-1] += a[i][j];
                        b[i][j-1] += a[i][j];
                        b[i][j+1] += a[i][j];
                        b[i+1][j-1] += a[i][j];
                    }
                }
            }
            for(int i=1;i<=9;i++)
            {
                for(int j=1;j<=9;j++)
                {
                    a[i][j] = b[i][j];
                }
            }
            for(int i=0;i<=9;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    b[i][j] = 0;
                }
            }
            
        }
        for(int i=1;i<=9;i++)
            {
                for(int j=1;j<=9;j++)
                {
                    if(j==9)
                    {
                        cout << a[i][j] << endl;
                    }
                    else
                    {
                    cout << a[i][j] << " ";
                    }
                }
            }
        
        system("PAUSE");
        return 0;
    }