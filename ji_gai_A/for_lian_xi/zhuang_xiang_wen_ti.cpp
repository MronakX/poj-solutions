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
        int x1, x2, x3, x4, x5, x6;
        while(cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6)
        {
            int sum = 0;
            if(x1<=0 && x2<=0 && x3<=0 && x4<=0 && x5<=0 && x6<=0)
            {
                break;
            }
        
            for(int i=1;;i++)
            {
            if(x1<=0 && x2<=0 && x3<=0 && x4<=0 && x5<=0 && x6<=0)
            {
                break;
            }

            if(x6 > 0)//fine
            {
                sum++;
                x6 --;
                continue;
            }

            if(x5>0)//fine
            {
                sum++;x5--;
                if(x1 > 0)
                {
                    x1 = x1-11;
                }
                
                continue;
            }
            
            if(x4 > 0)
            {
                sum++;x4--;//fine
                if(x2<5 && x2>=0)//fine
                {
                    int left = 20-4*x2;
                    x1 = x1 - left;
                    x2 = 0;
                }
                if(x2 >=5)//fine
                {
                    x2 = x2 - 5;
                }

                continue;
            }

            if(x3>0)
            {
                sum++;
                if(x3 == 3)
                {
                    x3 = 0;
                        if(x2==0 && x1 > 0)
                        {
                            x1 = x1 - 9;
                        }
                        if(x2 >= 1)
                        {
                            x2--;
                            if(x1>0)
                            {
                                x1 = x1 - 5;
                            }
                        }
                }
                if(x3 == 2)
                {
                    x3 = 0;
                        if(x2>=0 && x2 < 3)
                        {
                            if(x1 > 0)
                            {
                                int left1 = 18 - 4*x2;
                                x1 = x1 - left1; 
                            }
                            x2 = 0;
                        }
                        if(x2 >= 3)
                        {
                            x2 = x2 - 3;
                            if(x1 > 0)
                            {
                                x1 = x1 - 6;
                            }
                        }
                }

                if(x3 == 1)
                {
                    x3 = 0;
                    if(x2 >=0 && 5>=x2)
                    {
                        if(x1 > 0)
                        {
                            int left2 = 27 - 4*x2;
                            x1 = x1 - left2;
                        }
                        x2 = x2 - 5;
                    }
                    if(x2 >=5)
                    {
                        x2 = x2 - 5;
                        if(x1 > 0)
                        {
                            x1 = x1 -11;
                        }
                    }
                    
                }
                if(x3>=4)
                {
                    x3 = x3 -4;
                }
                continue;
            }
            if(x2 >=9)
            {
                sum ++;
                x2 = x2 - 9;
                continue;
            }
            if(x2 >=0 && x2<9)
            {
                sum++;
                if(x1 > 0)
                {
                    int left3 = 36 - 4*x2;
                    x1 = x1 - left3;
                }
                x2 = 0;
                continue;
            }
            
            if(x1 > 0 && x1 < 36)
            {
                sum++;
                x1 = 0;
                continue;
            }
            if(x1>36)   
            {
                sum++;
                x1 = x1 - 36;
                continue;
            }
            }
            
            
            cout << sum << endl;
            
        }
        system("PAUSE");
        return 0;
    }