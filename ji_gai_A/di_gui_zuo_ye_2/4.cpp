    /*
    郭大卫
    1900012995
    孙悟空找师傅
    19.11.13
    */    
    #include <iostream>
    #include <iomanip>
    #include <cstring>
    using namespace std;
    int b[60][60] = {}, a[60][60] = {};//a记录迷宫，b记录遍历情况
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;

    bool find(int x, int y)
    {
        if(x < 1 || y < 1 || x > m || y > n)//超出边界，false
        {
            return false;
        }
        if(b[x][y] || a[x][y] == 1)//遍历过，或是墙
        {
            return false;
        }
        b[x][y] = 1;
        if(a[x][y] == 3)//找到师傅，则true
        {
            return true;
        }
        for(int i=0; i<4; i++)
        {
            if(find(x+dx[i], y+dy[i]))//四个方向查找
            {
                return true;
            }
        }
        return false;//四个方向都找不到则false
    }
    int main()
    {
        int startx, starty;//起始位置
        cin >> m >> n;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i][j] == 2)
                {
                    startx = i;
                    starty = j;
                    break;
                }
            }
        }
        if(find(startx, starty))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        } 
        return 0;
    }