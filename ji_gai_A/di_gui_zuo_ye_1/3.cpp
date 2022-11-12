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
        int b[20]={}, flag = 0;
        void mult(int min, int max, int a[], int t)
        {
            int sum = 1;
            if(min>max)
            {
                for(int i=1;i<=max;i++)
                {
                    if(b[i])
                    {
                        sum *= a[i];
                    }
                }
                if(sum == t)
                {
                    flag = 1;
                }
            }
            else
            {
            b[min] = 0;
            mult(min+1, max, a,t);
            b[min] = 1;
            mult(min+1, max, a, t);
            }

        }
        int main()
        {
            int t, n, a[20];
            cin >> t >> n;
            for(int i=1;i<=n;i++)
            {
                cin >> a[i];
            }
            mult(1,n,a,t);
            if(flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            
            system("PAUSE");
            return 0;
        }