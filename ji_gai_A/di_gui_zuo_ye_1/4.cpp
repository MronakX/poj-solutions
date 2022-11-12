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
        int a[150][150] = {}, b[150][150] ={};
        void find(int x, int y)
        {
            if(!a[x][y])
            {
                return;
            }
            b[x][y] = 1;
            if(a[x-1][y] != 0 && b[x-1][y] != 1)
            find(x-1, y);
            if(a[x+1][y] != 0 && b[x+1][y] != 1)
            find(x+1, y);
            if(a[x][y-1] != 0 && b[x][y-1] != 1)
            find(x, y-1);
            if(a[x][y+1] != 0 && b[x][y+1] != 1)
            find(x, y+1);
        }
        int main()
        {
            int m, n, cnt = 0;
            cin >> m >> n;
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                   cin >> a[i][j];
                }
            }
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(!b[i][j] && a[i][j])
                    {
                        find(i,j);
                        cnt++;
                    }
                }
            }
            cout << cnt << endl;
            system("PAUSE");
            return 0;
        }