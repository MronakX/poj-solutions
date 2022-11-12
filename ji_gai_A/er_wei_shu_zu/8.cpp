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
        int n, flag = 0;
        double a[25][25]={};
        double b[25] = {};
        double avr[25] = {};
        double max[25] = {};
        double min[25] = {};
        cin >> n;
        for(int i=1;i<=7;i++)
            for(int j=1;j<=n;j++)
            {
                cin >> a[i][j];
            }

        for(int j=1;j<=n;j++)
        {
            max[j] = a[1][j];
            min[j] = a[1][j];
        }
        for(int j=1;j<=n;j++)
        {
            double sum =0;
            for(int i=1;i<=7;i++)
            {
                sum += a[i][j];
            }
            avr[j] = sum/7.0;
        }
        for(int i=1;i<=7;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(b[j] == 0 && (a[i][j] >= 42 || a[i][j] <= 32))//condition 1
                {
                    cout << j << " " << 4*(i-1) << ":00" << endl;
                    b[j] = 1;
                    flag = 1;
                    continue;
                }
                //condition 2
                if(i>=3 && b[j] == 0 && (a[i-2][j] >= 41 ||a[i-2][j] <= 33 ) && (a[i-1][j] >= 41 ||a[i-1][j] <= 33 ) && (a[i][j] >= 41 ||a[i][j] <= 33 ))
                {
                    cout << j << " " << 4*(i-1) << ":00" << endl;
                    b[j] = 1;
                    flag = 1;
                    continue;
                }
                //condition 3
                if(i>=2 && b[j] == 0 && fabs(a[i][j] - a[i-1][j]) >= 2)     
                {
                    cout << j << " " << 4*(i-1) << ":00" << endl;
                    b[j] = 1;
                    flag = 1;
                    continue;
                }
                //condition 4
                if(i==7 && b[j]==0 && (avr[j]>=40 || avr[j] <= 34))
                {
                    cout << j << " " << 4*(i-1) << ":00" << endl;
                    b[j] = 1;
                    flag = 1;
                }
                //condition 5
                if(a[i][j] > max[j])
                {
                    max[j] = a[i][j];
                }
                if(a[i][j] < min[j])
                {
                    min[j] = a[i][j];
                }
                if(b[j] == 0 && fabs(max[j]-min[j]>= 4))
                {
                    cout << j << " " << 4*(i-1) << ":00" << endl;
                    b[j] = 1;
                    flag = 1;
                    continue;
                }
            }
        }
        if(flag == 0)
        {
            cout << "None" << endl;
        }
        
        system("PAUSE");
        return 0;
    }