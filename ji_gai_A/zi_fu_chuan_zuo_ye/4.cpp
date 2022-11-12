        /*
        郭大卫
        1900012995
        求序列中的众数
        19.10.24
        */

        #include <iostream>
        #include <iomanip>
        #include <math.h>
        #include <string.h>
        using namespace std;
        int main()
        {
            int n;//n为行数
            char a[1000][1000], str[1000][1000];//a数组存储简化数据，str为输入数据
            int b[1000] = {};//b用来存储数字位数
            int c[1000] = {};//c用来存储出现次数
            
            cin >> n;
            for(int i=1; i<=n; i++)
            {
                
                cin.getline(str[i],130);
                if(str[i][0] == '\000')//若输入空行，则无视，计数--
                {
                i--;
                }
            }

            for(int i=1; i<=n; i++)
            {
                int cnt = 0;
                int flag1 = 1;//是否全是0  
                int flag2 = 1;//无关的0是否全部去掉
                for(int j=0; ; j++)
                {
                    if(j==0 && str[i][0] == '-')//第一个字符是负数，进行赋值
                    {
                        cnt++;
                        a[i][0] = str[i][j];
                    }

                    if(str[i][j] == '\000' && flag2 == 0)//该行结束，跳出循环
                    {
                        b[i] = cnt;
                        break;
                    }
                    if(str[i][j] == '\000' && flag2 == 1)//该行结束，且该行只有0或-0，那么这行的简化数据就是0，位数为1；
                    {
                        a[i][0] = '0';
                        b[i] = 1;
                        break;
                    }    
                    if(str[i][j] <='9' && str[i][j] >= '1')//出现第一个不为0的数字，标记为0
                    {
                        flag2 = 0;
                    }
                    if(flag2 == 0)//标记为0之后，即出现第一个非0数字后，再出现的所有数字都可以进行存储
                    {
                        a[i][cnt] = str[i][j];
                        cnt++;
                    }        
                }
            }
            //简化完毕，统计个数
            for(int i=1; i<=n; i++)//被比较的序列
            {
                for(int j=i+1; j<=n; j++)//与上述序列比较的序列，注意之前被比较过的序列不用比。
                {
                    int flag = 1;
                    for(int k=0; k<(max(b[i],b[j])); k++)//每一位比较都相等，则计数++；否则，一旦出现不等，则比较下一个序列
                    {
                        if(a[i][k] != a[j][k])
                        {
                            flag = 0;
                            break;
                        }    
                    }
                    if(flag == 1)
                    c[i]++;
                }
            }
            //准备输出次数最多的数字
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n-i; j++)
                {
                    if(c[j] < c[j+1])//冒泡排序
                    {
                        swap(c[j],c[j+1]);
                        for(int i=0; i<=max(b[j],b[j+1]); i++)
                        {
                        swap(a[j][i],a[j+1][i]);
                        }
                        swap(b[j],b[j+1]);
                    }
                }
        
            if(c[1] == n-1)//如果除去某个序列本身，剩下的序列都与之相同，则no
            {
                cout << "no" << endl;
            }
            else
            {
                for(int i=0; i<b[1]; i++)
                {
                    cout << a[1][i];
                }
            }


            system("PAUSE");
            return 0;
        }