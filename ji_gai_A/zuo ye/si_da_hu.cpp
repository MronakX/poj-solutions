/*
郭大卫
1900012995
四大湖
19.09.27
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{   
    int a, b, c, d;//a,b,c,d为排名
    int cc1, cc2, cc3, cc4;//cc1,cc2,cc3,cc4为四句话
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            for(int k=1;k<=4;k++)
                for(int l=1;l<=4;l++)//四轮枚举，共枚举4^4次
                {
                    a = i; 
                    b = j;
                    c = k;
                    d = l;//令四大湖的排名对应等于i/j/k/l
                    cc1 = (b==1) + (d==4) + (a==3);
                    cc2 = (d==1) + (b==4) + (a==2) + (c==3);
                    cc3 = (d==4) + (b==3);
                    cc4 = (a==1) + (c==4) + (d==2) + (b==3); //用编程语言写出四句话的意义
                    if(cc1==1 && cc2==1 && cc3==1 && cc4==1 && i!=j && i!=k && i!=l && j!=k && j!=l && k!=l)//四句话各有一部分对，且排名不会相同
                    {
                        cout << a << endl << b << endl << c << endl << d << endl;
                    }
                }
    
    system("PAUSE");
    return 0;
}