        /*
        郭大卫
        1900012995
        招聘会的人数
        19.10.09
        */

        #include <iostream>
        #include <iomanip>
        #include <math.h>
        #include <string.h>
        using namespace std;
        int main()
        {
            int x1, x2;
            int a[2000], b[2000],c[2000]={};
            cin.unsetf(ios::skipws);
            char enter;

            int i = 1, j = 1;
            
            while (cin >> x1 >> enter)
            {
                a[i]=x1;
                i++;
                if(enter == '\n')
                {
                    break;
                }
            }

            while (cin >> x2 >> enter)
            {
                b[j]=x2;
                j++;
                if(enter == '\n')
                {
                    break;
                }
            }
            for(int i1=1;i1<=i;i1++)
            {
                for(int i2=1;i2<=i-i1;i2++)
                {
                    if(a[i2] > a[i2+1])
                    {
                        swap(a[i2],a[i2+1]);
                    }
                    if(b[i2] > b[i2+1])
                    {
                        swap(b[i2], b[i2+1]);
                    }
                }//i是人数最大值
            }
            int min = a[1];//min是第一个人到的时间
            int max = b[i-1];//max是最后一个人走的时间
            
            for(int k=1;k<=i-1;k++)
            {
                for(int start = a[k];start<b[k+1];start++)
                {
                    c[start]++;
                }
            }
            for(int p=min;p<=max;p++)
            {
                for(int q=min;q<=max-1-p;q++)
                {
                    if(c[q]<c[q+1])
                    {
                        swap(c[q],c[q+1]);
                    }
                }
            }
            cout << i-1 << " " << c[min]-1 << endl;
            system("PAUSE");
            return 0;
        }