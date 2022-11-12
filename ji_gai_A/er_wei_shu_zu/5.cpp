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
        int m, n;
        char ch;
        int a[120][120] = {}, b[120][120] = {};
        cin >> n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                cin >> ch;
                if(ch == '#')
                {
                    a[i][j] = 0;
                    b[i][j] = 0;
                }
                if(ch == '.')
                {
                    a[i][j] = 1;
                    b[i][j] = 1;
                }
                if(ch == '@')
                {
                    a[i][j] = 2;
                    b[i][j] = 2;
                }
            }
        
        cin >> m;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(a[j][k] == 2)
                    {
                        if(a[j-1][k]==1)
                        {
                            b[j-1][k]=2;
                        }
                        if(a[j+1][k]==1)
                        {
                            b[j+1][k]=2;
                        }
                        if(a[j][k-1]==1)
                        {
                            b[j][k-1]=2;
                        }
                        if(a[j][k+1]==1)
                        {
                            b[j][k+1]=2;
                        }
                    }
                }
            }
            for(int p=1;p<=n;p++)
                for(int q=1;q<=n;q++)
                {
                    a[p][q] = b[p][q];
                }
        }
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j] == 2)
                {
                sum++;
                }
            }
        }
        cout << sum << endl;
        system("PAUSE");
        return 0;
    }