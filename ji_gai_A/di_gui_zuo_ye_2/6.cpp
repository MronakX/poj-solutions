    /*
    郭大卫
    1900012995
    幼儿园分糖果
    19.11.13
    */  
    #include <iostream>
    #include <iomanip>
    #include <cstring>
    #include <cmath>
    #include <algorithm>
    using namespace std;
    int a[8] = {2, 0, 2, 0, 0, 1, 0, 4};
    int b[8] = {};
    bool check(int year)
    {
        if(year%400==0 ||(year%100!=0 && year%4==0))
        {
            return true;
        }
        return false;
    }
    int main()
    {
        int k;
        cin >> k;
        
        while(k>0)
        {
            if(a[0] > 9)
            {
                cout << -1 << endl;
                break;
            }
            if(a[1] > 9)
            {
                a[0]++;
                a[1] = 0;
                continue;
            }
            if(a[2] > 9)
            {
                a[1]++;
                a[2] = 0;
                continue;
            }
            if(a[3] > 9)
            {
                a[2] ++;
                a[3] = 0;
                continue;
            }
            if(a[4] > 0)
            {
                a[3] ++;
                a[4] = 0;
                continue;
            }
            if(a[5] > 9)
            {
                a[3]++;
                a[5] = 1;
                continue;
            }
            if(a[6] > 3)
            {
                a[5]++;
                a[6] = 0;
                continue;
            }
            if(a[6] == 3 && a[7] > 0)
            {
                a[6]=0;
                a[7]=1;
                a[5]++;
                continue;
            }
            if(a[7] > 9)
            {
                a[6]++;
                a[7] = 0;
                a[5]++;
                continue;
            }
            if(a[0] == 4 || a[0] == 6 || a[0] == 8 || a[0] == 9)
            {
                a[0]++;
                continue;
            }
            b[1] = a[0] + a[1];
            {
                if(b[1] != 2 && b[1] != 3 && b[1] != 5 && b[1] != 7 && b[1] != 11 && b[1] != 13 && b[1] != 17)
                {
                    a[1]++;
                    continue;
                }
            }
            b[2] = b[1] + a[2];
            {
                if(b[2] != 2 && b[2] != 3 && b[2] != 5 && b[2] != 7 && b[2] != 11 && b[2] != 13 && b[2] != 17 && b[2] != 19 && b[2] != 23)
                {
                    a[2]++;
                    continue;
                }
            }

            b[3] = b[2] + a[3];
            if(b[3] != 2 && b[3] != 3 && b[3] != 5 && b[3] != 7 && b[3] != 11 && b[3] != 13 && b[3] != 17 && b[3] != 19 && b[3] != 23)
            {
                a[3]++;
                continue;
            }
            

            a[4] = 0;
            b[4] = b[3];

            b[5] = b[4] + a[5];
            if(b[5] != 2 && b[5] != 3 && b[5] != 5 && b[5] != 7 && b[5] != 11 && b[5] != 13 && b[5] != 17 && b[5] != 19 && b[5] != 23)
            {
                a[5]++;
                continue;
            }



            k--;
            if(k==0)
            {
                cout;
            }
        }
        system("PAUSE");
        return 0;
    }