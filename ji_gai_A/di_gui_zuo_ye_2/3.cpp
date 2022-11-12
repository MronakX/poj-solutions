        /*
        郭大卫
        1900012995
        放苹果问题
        19.11.13
        */
        #include <iostream>
        #include <iomanip>
        #include <cstring>
        using namespace std;
        int a[220][220] = {}, b[220][220] = {};//a存放图案，b记录是否遍历过
        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        void find(int x, int y)
        {
            b[x][y] = 1;//记录遍历
            for(int i=0; i<8; i++)
            {
                if(a[x+dx[i]][y+dy[i]] && !b[x+dx[i]][y+dy[i]])//相连位置有图，则继续寻找
                {
                    find(x+dx[i], y+dy[i]);
                }
            }
        }

        int main()
        {
            int m, n;
            char str[220][220];
            cin >> m >> n;
            for(int i=1; i<=m; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cin >> str[i][j];
                }
            }
            for(int i=1; i<=m; i++)//把字符转化成0或1，后续好写；0为空，1为图
            {
                for(int j=1; j<=n; j++)
                {
                    if(str[i][j] == '-')
                    {
                        a[i][j] = 0;
                    }
                    if(str[i][j] == '#')
                    {
                        a[i][j] = 1;
                    }
                }
            }
            int cnt = 0;
            for(int i=1; i<=m; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(a[i][j] && !b[i][j])//某个位置有图案，且不与别的图案相连，则开始寻找
                    {
                        find(i, j);
                        cnt++;
                    }
                }
            }
            cout << cnt << endl;
            system("PAUSE");
            return 0;
        }