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
        int m, n, absum;
        long long sum;
        cin >> m >> n;
        int a[200][200] = {};//v
        int b[200][200] = {};//v
        int c[200][200] = {};//v
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                cin >> a[i][j];//v
            }

        int r, s;
        cin >> r >> s;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=s;j++)
            {
                cin >> b[i][j];//v
            }
        sum = 100000000000;//v
        for(int i=1;i<=m-r+1;i++)
            for(int j=1;j<=n-s+1;j++)//前两层找左上角起始点
            {
                //左上角的点为a[i][j]
                
                absum = 0;
                int num1 = 1;
                int num2 = 1;
                for(int p=i;p<=i+r-1;p++)
                {
                    for(int q=j;q<=j+s-1;q++)
                    {
                        if(num2 == s+1)
                        {
                            num2 = 1;
                            num1 ++;
                        }
                        int minus = a[p][q] - b[num1][num2];
                        absum += fabs(minus);
                        num2 ++;
                        
                    }
                }
                if(absum < sum)
                {
                    num1 = 1;
                    num2 = 1;
                    sum = absum;
                    for(int p=i;p<=i+r-1;p++)
                        for(int q=j; q<=j+s-1; q++)
                        {
                            if(num2 == s+1)
                            {
                                num2 = 1;
                                num1 ++;
                            }
                            c[num1][num2] = a[p][q];
                            num2 ++;
                            
                        }
                }
            }
            for(int i=1;i<=r;i++)
                for(int j=1;j<=s;j++)
                {
                    if(j == s)
                    {
                        cout << c[i][j] << endl;
                    }
                    else
                    cout << c[i][j] << " ";
                }
        system("PAUSE");
        return 0;
    }