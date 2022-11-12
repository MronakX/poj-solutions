    /*
    郭大卫
    1900012995
    二维数组回形遍历
    19.10.16
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int row, col;//row为行数，col为列数
        int a[105][105], b[105][105]={0};//a数组存放矩阵，b数组标记矩阵某点是否经过遍历
        cin >> row >> col;
        for(int i=1; i<=row; i++)//输入数组
            for(int j=1; j<=col; j++)
            {
                cin >> a[i][j];
            }
        int cnt = 0;//cnt记录转了几圈
        while(cnt < row && cnt < col)//当转圈数小于行数、列数时，循环继续
        {
            for(int i=1+cnt; i<=col-cnt; i++)//水平方向向右循环，每次开始、结束的位置各多/少一个cnt
            {
                if(b[cnt+1][i] == 0)
                {
                cout << a[cnt+1][i] << endl;//某点没经过遍历，则输出，并标记
                b[cnt+1][i] = 1;
                }
            }

            for(int i=2+cnt; i<=row-cnt-1; i++)//垂直方向向下循环，每次开始、结束的位置各多/少一个cnt
            {   
                if(b[i][col-cnt] == 0)
                {
                cout << a[i][col-cnt] << endl;
                b[i][col-cnt] = 1;
                }
            }

            for(int i=col-cnt; i>=1+cnt; i--)//水平方向向左循环，每次开始、结束的位置各多/少一个cnt
            {
                if(b[row-cnt][i] == 0)
                {
                cout << a[row-cnt][i] << endl;
                b[row-cnt][i] = 1;
                }
            }

            for(int i=row-1-cnt; i>=2+cnt; i--)//垂直方向向上循环，每次开始、结束的位置各多/少一个cnt
            {
                if(b[i][cnt+1] == 0)
                {
                cout << a[i][cnt+1] << endl;
                b[i][cnt+1] = 1;
                }
            }
            cnt++;//圈数+1；
        }
        system("PAUSE");
        return 0;
    }