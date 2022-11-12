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
        //先找因数，再找质因数
        int x1, x2, a[2000], b[2000];
        char dot;
        cin >> x1 >> dot >> x2;
        int a1=1,a2=1,sum1=0, sum2=0;
        int k1 = sqrt(x1);
        for(int i=2;i<=x1;i++)//i是因数
        {
            if(x1 % i == 0)
            {
                int k2 = sqrt(i);
                int flag = 1;
                for(int j=2;j<=k2;j++)
                {
                    if(i%j==0)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    a[a1]=i;
                    a1++;
                    sum1++;
                }
            }
        }
        int k3 = sqrt(x2);
        for(int p=2;p<=x2;p++)
        {
            if(x2 % p == 0)
            {
                int k4 = sqrt(p);
                int flag1 = 1;
                for(int q=2;q<=k4;q++)
                {
                    if(p%q==0)
                    {
                        flag1 = 0;
                        break;
                    }
                }
                if(flag1 == 1)
                {
                    b[a2]=p;
                    a2++;
                    sum2 ++;

                }
            }
        }
        int sum;
        if(sum1 >=sum2)
        sum = sum1;
        if(sum1 <sum2)
        sum = sum2;
        int g = 1;
        for(int w=1;w<=sum;w++) 
        {
            if(a[w] != b[w])
            {
                cout << "NO" << endl;
                g = 0;
                break;
            }
        }
        if(g==1)
        {
            cout << "YES" << endl;
        }
        system("PAUSE");
        return 0;
    }