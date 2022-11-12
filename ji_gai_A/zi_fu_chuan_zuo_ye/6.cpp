    /*
    郭大卫
    1900012995
    紧急措施
    19.10.24
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        char str1[1000], str2[1000], str3[1000], a[1000], b[1000], c[1000], d[1000];
        //str1存储邮箱，str2为输入的字符串，str3去掉干扰字符，a存储账号，b存储密码，c存储邮箱，d存储修改后密码
        int i, n, j, k, l, g=0;//ijkl为循环值，g为标记
        int lengtha, lengthb, lengthc;//分别是abc字符串的长度
        cin.getline(str1,1000);
        int primeLength = strlen(str1);//邮箱长度
        cin >> n;
        cin.getline(str3,1000);
        for(int p=0; p<n; p++)
        {
            cin.getline(str2,1000);
            int length = strlen(str2);
            for(j=0; j<length; j++)
            {
                if(str2[j] == ' ')//输入空格时，截止，账号存储完成
                {
                    lengtha = j;
                    break;
                }
                a[j] = str2[j];
            }
            for(k=0; k<length; k++)
            {
                if(str2[k+j+1] == ' ')//输入空格时，截止，密码存储完成
                {
                    lengthb = k;
                    break;
                }
                b[k] = str2[k+j+1];
            }
            for(l=0; l<length; l++)
            {
                if(l+k+j+1 == length)//总长度等于初始字符串的长度，则截止，邮箱存储完成
                {
                    lengthc = l;
                    break;
                }
                c[l] = str2[l+k+j+2];
            }
            int flag = 1;
            for(i=0; i<primeLength; i++)//先比对邮箱是否一致
            {
                if(str1[i] != c[i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)//邮箱一致时，开始改密码
            {
                
                for(i=0; i<=lengthb; i++)
                {
                    if(b[i] >= 'A' && b[i] <= 'Z')//大写变小写
                    {
                        d[i] = b[i] + 32;
                    }
                    if(b[i] >= 'a' && b[i] <= 'z')//小写变大写
                    {
                        d[i] = b[i] - 32;
                    }
                    if(b[i] <'A' || b[i] > 'z')//不是字母，原样存储
                    {
                        d[i] = b[i];
                    }
                }
            }

            if(flag == 1)
            {
                g = 1;//有解置为1
                for(int i=0; i<lengtha; i++)//输出账号
                {
                    cout << a[i];
                }
                cout << " ";
                for(int i=0; i<lengthb; i++)//输出修改后密码
                {
                    cout <<d[i];
                }
                cout << endl;
            }
        }
        if(g == 0)//无解，输出empty
        {
            cout << "empty" << endl;
        }
        system("PAUSE");
        return 0;
    }