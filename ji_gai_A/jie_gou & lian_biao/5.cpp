/*
郭大卫
1900012995
八皇后
19.12.18
*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int str[100][8] = {};//存放所需的全部八位数字，每个单元只存放一个数字
int grid[20][20] = {};//棋盘
int cnt = 1;
int row[20] = {};//行
int leftd[20] = {};//左斜对角
int rightd[20] = {};//右斜对角

void find(int column)
{
    if(column == 9)//边界条件
    {
        for(int j=1;j<=8;j++)//先列后行遍历，确定答案从小到大存放
        {
            for(int i=1;i<=8;i++)
            {
                if(grid[i][j])
                {
                    str[cnt][j] = i;//存放答案
                }
            }
        }
        cnt++;
        return;
    }
    else
    {
        for(int i=1; i<=8; i++)
        {
            if(!row[i] && !leftd[i + column - 1] && !rightd[8 + i - column])
            {
                grid[i][column] = 1;
                row[i] = 1;
                leftd[i + column - 1] = 1;
                rightd[8 + i - column] = 1;
                find(column + 1);
                grid[i][column] = 0;//回溯
                row[i] = 0;
                leftd[i + column - 1] = 0;
                rightd[8 + i - column] = 0;
            }
        }
    }        
}

int main()
{
    find(1);
    int n;
    cin >> n;
    int num1;
    cin >> num1;
    for(int j=1; j<=8; j++)
    {
        cout << str[num1][j];
    }
    for(int i=1; i<n; i++)
    {
        cout << endl;
        int num;
        cin >> num;
        for(int j=1; j<=8; j++)
        {
            cout << str[num][j];
        }
    }
    return 0;
}