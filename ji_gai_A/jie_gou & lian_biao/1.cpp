/*
郭大卫
1900012995
窗口管理
19.12.18
*/
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct Window{
    int id, x, y, w, h;
};
int main()
{
    Window win[1010] = {};
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> win[i].id >> win[i].x >> win[i].y >> win[i].w >> win[i].h; 
    }
    for(int i=1;i<=m;i++)
    {
        int xx, yy;
        cin >> xx >> yy;
        int g = 0;//标志是否点击窗口
        for(int i=1; i<=n; i++)//从最上层的窗口开始检查
        {
            if(xx >= win[i].x && yy >= win[i].y && xx < win[i].x + win[i].w && yy < win[i].y + win[i].h)
            {
                cout << win[i].id << " " << xx - win[i].x << " " << yy - win[i].y << endl;
                Window temp = win[i];
                if(i != 1)//将点击的窗口置于最上层
                {
                    for(int j=i-1; j>=1; j--)
                    {
                        win[j+1] = win[j]; 
                    }
                    win[1] = temp;
                }
                g = 1;
                break;
            }
        }
        if(!g)
        {
            cout << "desktop!" << endl;
        }
    }
    system("PAUSE");
    return 0;
}