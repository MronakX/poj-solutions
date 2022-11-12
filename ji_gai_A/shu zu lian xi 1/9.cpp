    /*
    郭大卫
    1900012995
    求交集
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
        int a[2000]={}, b[2000],c[2000]={};
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
        i--;
        while (cin >> x2 >> enter)
        {
            b[j]=x2;
            j++;
            if(enter == '\n')
            {
                break;
            }
        }
        j--;
        for(int i1=1;i1<=i;i1++)
        {
            for(int i2=1;i2<=i-i1;i2++)
            {
                if(a[i2] > a[i2+1])
                {
                    swap(a[i2],a[i2+1]);
                }
                
            }//i是第一行元素个数
        }
        for(int i3=1;i3<=j;i3++)
        {
            for(int i4=1;i4<=j-i3;i4++)
            {
                if(b[i4] > b[i4+1])
                {
                    swap(b[i4], b[i4+1]);
                }
            }
        }
        int flag = 0;
        int g=0;
        for(int p=1;p<=i;p++)
        {
            for(int q=1;q<=j;q++)
            {
                if(a[p]!=a[p-1] && a[p]==b[q] && flag == 1)
                {
                    cout << "," << a[p];
                    
                    break;
                }
                if(a[p]!=a[p-1] && a[p]==b[q] && flag == 0)
                {
                    cout << a[p];
                    g=1;
                    flag = 1;
                    break;
                }
            }
        }
        if(g==0)
        {
            cout << "NULL" << endl;
        }
        system("PAUSE");
        return 0;
    }