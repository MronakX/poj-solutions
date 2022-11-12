    /*
    郭大卫
    1900012995
    水淹七军
    19.11.13
    */    
    #include <iostream>
    #include <iomanip>
    #include <cstring>
    using namespace std;
    int a[220][220], b[220][220];//a存储高度，b记录遍历
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;
    void find(int x, int y)
    {
        if(x < 1 || y < 1 || x > m || y > n)//超出边界
        {
            return;
        }
        b[x][y] = 1;
        for(int i=0; i<4; i++)
        {
            if((a[x+dx[i]][y+dy[i]] < a[x][y]))//如果某点高度比相邻的高，则不论相邻位置之前有没有水，都更新为更大的水高
            {
                a[x+dx[i]][y+dy[i]] = a[x][y]; 
                find(x+dx[i], y+dy[i]);
            }
            else if(!b[x+dx[i]][y+dy[i]] && (a[x+dx[i]][y+dy[i]] == a[x][y]))//如果相邻没被遍历过，且高度相同，同样查找
            {
                find(x+dx[i], y+dy[i]);
            }
        }
    }
    int main()
    {
        int k;
        cin >> k;
        for(int q=0; q<k; q++)
        {   
            int flag = 0;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            cin >> m >> n;
            for(int i=1; i<=m; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    cin >> a[i][j];
                }
            }
            int endx, endy;
            cin >> endx >> endy;//司令部位置
            int p, startx, starty;
            cin >> p;
            for(int i=0; i<p; i++)
            {
                cin >> startx >> starty;
                find(startx, starty);
                if(b[endx][endy] && !flag)
                {
                    flag = 1;
                    cout << "Yes" << endl;//不能加break,否则剩余数据会被当成下一组的读入
                }
            }
            if(!flag)
            {
                cout << "No" << endl;
            }
        }
        system("PAUSE");
        return 0;
    }