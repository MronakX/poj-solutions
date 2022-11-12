    /*
    郭大卫
    1900012995
    护林员盖房子
    19.10.17
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int m, n, k, square;//m为行数，n为列数，k为高度，square为面积
        int a[25][25] = {};
        int b[25][25] = {};//b为某一点向它的左侧最长为0序列的宽度，如某个点为0，则该点置为1；如某个点为0，且左侧有3个0连续，则为4
        cin >> m >> n;
        for(int i=0; i<=m+3; i++)
            for(int j=0; j<=n+3; j++)
                a[i][j] = 1;//把矩阵之外的值全置为1

        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                cin >> a[i][j];//输入矩阵
            
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                if(a[i][j] == 0)
                {
                    b[i][j] = b[i][j-1] + 1;//b[i][j]为左侧最长0序列宽度（另外，因为数组第0列已经置为0，故不用考虑第1列的问题，如果第一列有0，那么宽度为0+1=1）
                }
            }
        int smax = 0;//smax为面积最大值
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                if(a[i][j] == 0)//i为行指标，j为列指标
                {
                    for(int k=0; k<=m; k++)//从高度为0开始，向下遍历
                    {
                        if(b[i][j] == 0)//宽度为0，则结束
                        {
                            square = 0;
                            smax = max(smax, square);
                            //cout << k+1 << " " << b[i][j] << " " << square <<  endl;//debug用的
                            break;
                        }
                        for(int p=j;p>j-b[i][j];p--)//在某个0序列的下方开始从右向左遍历
                        {
                            if(a[i+k][p]==1)//如果下方某一行的某个点为1，则停止，记录面积最大值。同时，宽度-1，将k置为0，重新开始向下遍历
                            {
                                square = k * b[i][j];
                                smax = max(smax, square);
                                //cout << k << " " << b[i][j] << " " << square <<  endl;//debug用的
                                b[i][j]--;
                                k = 0;
                                break;
                            }

                        }
                    }
                    
                }
            }
        cout << smax << endl;

        
        system("PAUSE");
        return 0;
    }