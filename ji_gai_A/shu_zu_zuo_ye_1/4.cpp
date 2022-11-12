    /*
    郭大卫
    1900012995
    两倍
    19.10.09
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int num, sum;//num为输入的数字，sum为总个数
        int i = 1;
        int a[16] = {};//数组清零
        while(cin >> num)
        {
            if(num != 0 && num != -1)
            {
                a[i] = num;
                i++;//数组中共有i-1个元素
            }
            if(num == 0)//当输入0时，该行数组赋值完成，进行检验和归零
            {
                sum = 0;
                for(int j=1; j<=i-1; j++)
                {
                    for(int k=1; k<=i-1; k++)
                    {
                        if(a[j] == 2*a[k])//遍历检验，如有二倍则计数加1
                        {
                            sum ++;
                        }
                    }
                }
                cout << sum << endl;
                for(int z=0; z<=16; z++)
                {
                    a[z] = 0;//数组归零
                }
                i = 1;//下标归1
            }
            if(num == -1)//输入-1，程序终止
            {
                break;
            }
        }
        
        system("PAUSE");
        return 0;
    }