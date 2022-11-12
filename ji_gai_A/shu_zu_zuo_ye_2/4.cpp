    /*
    郭大卫
    1900012995
    话题焦点
    19.10.16
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int a[10001][40] = {0};//a数组存放输入的数据
        int b[1000] = {0};//b数组记录某个人被提及次数
        int c[10001] = {0};//c数组用于冒泡排序，输出序号
        int n;//n为韦伯数量
        cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> a[i][1] >> a[i][2];//先输入发微博的人的序号，和提到的人数
            for(int j=1; j<=a[i][2]; j++)
            {
                cin >> a[i][2+j];//输入提到的序号
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=3; j<=30; j++)
            {
                b[a[i][j]]++;//统计每个序号被提到的次数
            }
        }
        int max = b[1];//max为最多次数
        int maxNum = 1;//maxnum为该序号
        for(int i=1; i<=100; i++)//
        {
            if(b[i] > max)//如果b中某个序号的次数多于max，则置为新的最大值
            {
            max = b[i];
            maxNum = i;
            }
        }
        cout << maxNum << endl;

        int k = 1;
        for(int i=1; i<=n; i++)
            for(int j=3; j<=30; j++)
            {
                if(a[i][j] == maxNum)//遍历记录提到maxNum的序号
                {
                c[k] = a[i][1];
                k++;
                }
            }

        for(int i=1; i<=k-1; i++)//冒泡循环，从小到大排序
            for(int j=1; j<=k-1-i; j++)
            {
                if(c[j] > c[j+1])
                swap(c[j], c[j+1]);
            }

        cout << c[1];
        for(int i=2; i<=k-1; i++)
        {
            if(c[i] != c[i-1])//避免重复输出同一个序号
            cout << " " << c[i];
        }
        system("PAUSE");
        return 0;
    }