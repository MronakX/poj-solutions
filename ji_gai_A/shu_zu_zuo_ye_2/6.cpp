    /*
    郭大卫
    1900012995
    错误探测
    19.10.16
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int n;
        while(cin >> n)
        {
            if(n == 0)//输入0时，终止程序
            {
                break;
            }
            else
            {
                int a[101][101] = {};//a存放矩阵
                int b[101] = {}, c[101] = {};//b存放每一行1的个数，c存放每一列的1的个数
                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                    {
                        cin >> a[i][j];
                    }

                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                    if(a[i][j] == 1)//记录1的个数
                    {
                        b[i]++;
                        c[j]++;
                    }
                int flag = 1;//flag1用于标记是否“OK”
                int num1 = 0, num2 = 0, sum1 = 0, sum2 = 0;//num1，num2为情况2时可以改变的那个数字的行、列指标；sum1，sum2记录“存在奇数个1”的行、列的个数
                for(int i=1; i<=n; i++)
                {
                    if(b[i] % 2 != 0 || c[i] % 2 != 0)//某一行或某一列有奇数个1，则标记0
                    {
                        flag = 0;
                    }
                }
                if(flag == 1)
                {
                    cout << "OK" << endl;
                }
                if(flag == 0)
                {
                    for(int i=1; i<=n; i++)
                    {
                        if(b[i] % 2 == 1)//当某一行有奇数个1，记录该行的行指标，且数量+1
                        {
                            sum1++;
                            num1 = i;
                        }
                        if(c[i] % 2 == 1)//同上，行换成列
                        {
                            sum2++;
                            num2 = i;
                        }
                    }
                    if(sum1 == 1 && sum2 == 1)//如果只分别存在1个“有奇数个1”的行和列，那么只需要改变列交界处的数字即可
                    {
                        cout << "Change bit (" << num1 << "," << num2 << ")" << endl;
                    }
                    else//否则，情况三
                    {
                        cout << "Corrupt" << endl;
                    }
                }
            }
        }
        system("PAUSE");
        return 0;
    }