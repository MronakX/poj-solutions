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
        int a[101][101];
        int n, cnt, minRow, minColumn;
        cin >> cnt;
        for(int c=0;c<cnt;c++)
        {
            int sum=0;
            n = cnt;
            for(int i=1;i<=n;i++)//输入矩阵
            {
                for(int j=1;j<=n;j++)
                {
                    cin >> a[i][j];
                }
            }
            while(n>=2)
            {
                
                for(int p=1;p<=n;p++)
                {
                    minRow = a[p][1];
                    for(int q=1;q<=n;q++)
                    {
                        if(a[p][q]<minRow)
                        {
                            minRow = a[p][q];
                        }
                    }
                    for(int r=1;r<=n;r++)
                    {
                        a[p][r]-=minRow;
                    }
                }

                for(int i=1;i<=n;i++)
                {
                    minColumn = a[1][i];
                    for(int j=1;j<=n;j++)
                    {
                        if(a[j][i]<minColumn)
                        {
                            minColumn = a[j][i];
                        }
                    }
                    for(int k=1;k<=n;k++)
                    {
                        a[k][i] -= minColumn;
                    }
                }
                //cout << minRow << minColumn << a[1][1] << " " << a[1][2] << " "  << a[2][1] << " "  << a[2][2] << " ";
                sum = sum + a[2][2];

                for(int i=2;i<n;i++)
                {
                    for(int j=2;j<n;j++)
                    {
                        a[i][j] = a[i+1][j+1];
                    }
                    a[i][1] = a[i+1][1];
                    a[1][i] = a[1][i+1];
                }
                n--;
            }
            cout << sum << endl;
        }
        system("PAUSE");
        return 0;
    }