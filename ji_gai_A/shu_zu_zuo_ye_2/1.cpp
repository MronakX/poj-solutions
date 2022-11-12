    /*
    郭大卫
    1900012995
    计算鞍点
    19.10.16
    */   
    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;

    int main()
    {
        int a[6][6];

        for(int i=1; i<=5; i++)
            for(int j=1; j<=5; j++)//输入5*5数组
            {
                cin >> a[i][j];
            }
        int flag3 = 0;//flag3标记是否有解
        for(int i=1; i<=5; i++)//行指标
            for(int j=1; j<=5; j++)//列指标
            {
                int flag1 = 1;//flag1用来标记是否同行最大
                int flag2 = 1;
                for(int k=1; k<=5; k++)//同行，不同列,要同行最大
                {
                    if(a[i][k] > a[i][j])//如果同行有比它大的数，标记置为0，跳出
                    {
                        flag1 = 0;
                        break;
                    }
                }
                for(int k=1; k<=5; k++)//同列最小，同理
                {
                    if(a[k][j] < a[i][j])
                    {
                        flag2 = 0;
                        break;
                    }
                }
                if(flag1 == 1 && flag2 ==1)//如果满足同行最大，同列最小，则输出，并将有解标记置为1
                {
                    flag3 = 1;
                    cout << i << " " <<  j << " " << a[i][j] << endl;
                }
            }
        if(flag3 == 0)//无解，则notfound
        {
            cout << "not found" << endl;
        }
        system("PAUSE");
        return 0;
    }