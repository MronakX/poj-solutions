/*
郭大卫
1900012995
蛇形矩阵
19.10.09
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n;
    int a[17][17];
    int b[17][17];
    cin >> n;
    //标记数组清零
    for(int w=0;w<17;w++)
        for(int v=0;v<17;v++)
        {
            b[w][v]=1;
        }
    for(int p=1;p<=n;p++)
        for(int q=1;q<=n;q++)
        {
            b[p][q]=0;
        }
    
    //主体
    int k, i=1, j=1;//i为行指标 j为列指标
    a[1][1]=1;
    for(k=2;k<=n*n;k++)
    {
        if(b[i-1][j+1]==0)//右上无占位符，则右上移动
        {
            a[i-1][j+1]=k;
            b[i-1][j+1]=1;
            i--;
            j++;
            //cout << i << " " << j << endl;
            continue;
        }
        if(b[i+1][j-1]==0)//左下移动
        {
            a[i+1][j-1]=k;
            b[i+1][j-1]=1;
            i++;
            j--;
                        //cout << i << " " << j << endl;
                        continue;

        }
        if(b[i-1][j+1]!=0 && b[i+1][j-1]!=0)
        {
            if(i==1 && j<n)//youyi
            {
                a[i][j+1]=k;
                b[i][j+1]=1;
                i=i;
                j++;
                
                            //cout << i << " " << j << endl;
                            continue;

            }
            if(i!=1 && i!=n && j==1)//下移
            {
                a[i+1][j]=k;
                b[i+1][j]=1;
                i++;
                j=j;
                
                            //cout << i << " " << j << endl;
                            continue;

            }
            if(i==n)//youyi
            {
                a[i][j+1]=k;
                b[i][j+1]=1;
                i=i;
                j++;            
                //cout << i << " " << j << endl;
                continue;


            }
            if(j==n)//xiayi
            {
                a[i+1][j]=k;
                b[i+1][j]=1;
                i++;
                j=j;
                            //cout << i << " " << j << endl;
                            continue;

            }
            cout << k << endl;
        }
    }
    
        for(int g=1;g<=n;g++)
        {
            for(int h=1;h<=n;h++)
            {
                if(h%n==0)
                {
                    cout << a[g][h] << endl;
                }
                else
                {
                    cout << a[g][h] << " " ;
                }
            }
        }
    system("PAUSE");
    return 0;
}