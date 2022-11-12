        /*
        郭大卫
        1900012995
        
        19.10.09
        */

        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
        int main()
        {
            int k;
            cin >> k;
            int a[8] = {};
            int b[8] = {};
            int cnt = 0;
            int t, flag1;
            for(int i=2020; i<10000;i++)
            {
                a[0] = i/1000;
                b[0] = a[0];
                t = sqrt(b[0]);
                flag1 = 1;
                for(int j=2;j<=t;j++)
                {
                    if(b[0] % j == 0)
                    {
                        flag1 = 0;
                        break;
                    }
                }
                if(!flag1)
                    continue;


                a[1] = i%1000/100;
                b[1] = b[0] + a[1];
                t = sqrt(b[1]);
                flag1 = 1;
                for(int j=2;j<=t;j++)
                {
                    if(b[1] % j == 0)
                    {
                        flag1 = 0;
                        break;
                    }
                }
                if(!flag1)
                    continue;

                a[2] = i%1000%100/10;
                b[2] = b[1] + a[2];
                t = sqrt(b[2]);
                flag1 = 1;
                for(int j=2;j<=t;j++)
                {
                    if(b[2] % j == 0)
                    {
                        flag1 = 0;
                        break;
                    }
                }
                if(!flag1)
                    continue;

                a[3] = i%10;
                b[3] = b[2] + a[3];
                t = sqrt(b[3]);
                flag1 = 1;
                for(int j=2;j<=t;j++)
                {
                    if(b[3] % j == 0)
                    {
                        flag1 = 0;
                        break;
                    }
                }
                if(!flag1)
                    continue;

                for(int j=0;j<=1;j++)//a4
                {
                    if(j==0)
                    {
                        a[4] = j;
                        b[4] = b[3] + a[4];
                        for(int p=1;p<=9;p++)//a[5] 月份第二位
                        {
                            a[5] = p;
                            b[5] = b[4] + a[5];
                            t = sqrt(b[5]);
                            flag1 = 1;
                            for(int q=2;q<=t;q++)
                            {
                                if(b[5] % q == 0)
                                {
                                    flag1 = 0;
                                }
                            }
                            if(!flag1)
                            {
                                continue;
                            }

                            for(int n=0;n<=3;n++)//a[6]
                            {
                                if(n==0)
                                {
                                    a[6] = 0;
                                    for(int m=1;m<=9;m++)//a[7]
                                    {
                                        a[7] = m;
                                        b[7] = b[5] + a[7];
                                        t = sqrt(b[7]);
                                        flag1 = 1;
                                        for(int c=2; c<=t;c++)
                                        {
                                            if(b[7] % c == 0)
                                            {
                                                flag1 = 0;
                                            }
                                        }
                                        if(flag1)
                                        {
                                            cnt++;
                                            if(cnt == k)
                                            {
                                                cout << a[0] << a[1] << a[2] << a[3] << "/" << a[4] << a[5] << "/" << a[6] << a[7] << endl;
                                            }
                                        }
                                    }
                                }
                                if(n==2)
                                {
                                    a[6] = 2;
                                    b[6] = b[5] + a[6];
                                    t = sqrt(b[6]);
                                    flag1 = 1;
                                    for(int c=2;c<=t;c++)
                                    {
                                        if(b[6] % c == 0)
                                        {
                                            flag1 = 0;
                                        }
                                    }
                                    if(!flag1)
                                    {
                                        continue;
                                    }

                                    if(a[5] == 2)
                                    {
                                        for(int c=2;c<=8;c++)
                                        {
                                            a[7] = c;
                                            b[7] = b[6] + a[7];
                                            t = sqrt(b[7]);
                                            flag1 = 1;
                                            for(int d=2;d<=t;d++)
                                            {
                                                if(b[7] % d == 0)
                                                {
                                                    flag1 = 0;
                                                }
                                            }
                                            if(flag1)
                                            {
                                                cnt++;
                                                if(cnt == k)
                                                {
                                                    cout << a[0] << a[1] << a[2] << a[3] << "/" << a[4] << a[5] << "/" << a[6] << a[7] << endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }


            }
            return 0;
        }