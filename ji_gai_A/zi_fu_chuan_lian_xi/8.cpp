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
    int n; 
    char a[15][15]={}, b[15][15] ={}, new1[15][15] ={}, new2[15][15] ={}, new3[15][15] ={}, new4[15][15] ={};

    void f1()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1; j<=n; j++)
            {
                new1[j][n+1-i] = a[i][j]; 
            }
        }
    }

    void f2()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1; j<=n; j++)
            {
                new2[n+1-j][i] = a[i][j]; 
            }
        }
    }

    void f3()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1; j<=n; j++)
            {
                new3[n+1-i][n+1-j] = a[i][j]; 
            }
        }
    }

    void f4()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1; j<=n; j++)
            {
                new4[i][j] = a[i][j]; 
            }
        }
    }


    int main()
    {
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin >> a[i][j];
            }
        }
        f1();
        f2();
        f3();
        f4();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin >> b[i][j];
            }
        }
        int flag1 = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i][j] != new1[i][j])
                {
                    i=n;
                    flag1 = 0;
                    break;
                }
            }
        }
        if(flag1 == 1)
        {
            cout << 1 << endl;
        }

        int flag2 = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i][j] != new2[i][j])
                {
                    i=n;
                    flag2 = 0;
                    break;
                }
            }
        }
        if(flag2 == 1)
        {
            cout << 2 << endl;
        }
        int flag3 = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i][j] != new3[i][j])
                {
                    i=n;
                    flag3 = 0;
                    break;
                }
            }
        }
        if(flag3 == 1)
        {
            cout << 3 << endl;
        }
        int flag4 = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[i][j] != new4[i][j])
                {
                    i=n;
                    flag4 = 0;
                    break;
                }
            }
        }
        if(flag4 == 1)
        {
            cout << 4 << endl;
        }

        if(flag1==0 && flag2 ==0 && flag3 ==0 && flag4==0)
        {
            cout << 5 << endl;
        }
        system("PAUSE");
        return 0;
    }