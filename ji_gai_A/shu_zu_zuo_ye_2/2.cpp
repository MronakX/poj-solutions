    /*
    郭大卫
    1900012995
    寻找山顶
    19.10.16
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int m, n;//m为行，n为列
        int a[25][25] = {0};//数组清零，确保边界为0；
        cin >> m >> n;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                cin >> a[i][j];//输入m*n数组
            }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]>=a[i-1][j] && a[i][j]>=a[i+1][j] && a[i][j]>=a[i][j-1] && a[i][j]>=a[i][j+1])//如果某点的数字大于等于相邻四个点，则为山顶
                {
                    cout << i-1 << " " << j-1 << endl;;
                }
                
            }
        }
        
        system("PAUSE");
        return 0;
    }