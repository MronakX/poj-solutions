/*
郭大卫
1900012995
BFS A:Saving Tang Monk
BFS + 状态压缩记录重复到达 + 剪枝
20.05.27
*/
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
    int x;
    int y;
    int step;
    int snake;
    int key;
    Node(int xx, int yy, int ss, int sn, int kk)
    {
        x = xx;
        y = yy;
        step = ss;
        snake = sn;
        key = kk;
    }
};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char a[102][102] = {};
int visited[102][102][12] = {};//v[i][j][k]代表到达i，j，手持k钥匙时的最小步数
int m, n;
int ans;

queue<Node> q;

void bfs()
{
    while (!q.empty())
    {
        Node p = q.front();
        q.pop();
        //cout << p.x << " " << p.y << " key:" << p.key << " step:" << p.step << endl;
        //cout << "minstep" << visited[p.x][p.y][p.key] << endl;
        if (a[p.x][p.y] == 'T' && p.key == m)
        {
            ans = min(ans, p.step - 1);
            continue;
        }
        visited[p.x][p.y][p.key] = p.step;
        for (int i = 0; i < 4; i++)
        {
            int next_x = p.x + dx[i];
            int next_y = p.y + dy[i];
            int next_key = p.key;
            int next_snake = p.snake;
            int next_step = p.step + 1;
            if (a[next_x][next_y] == 0 || a[next_x][next_y] == '#')
                continue;
            if (a[next_x][next_y] - '0' == p.key + 1)
            {
                next_key++;
            }
            if((visited[next_x][next_y][next_key] <= next_step) && (visited[next_x][next_y][next_key] != 0))
            {
                continue;
            }
            visited[next_x][next_y][next_key] = next_step;//这句内部提前剪枝很重要，否则MLE
            if (a[next_x][next_y] >= ('S' + 30))//每条蛇只杀一次，杀完后记录
            {
                int snake_id = (a[next_x][next_y] - 'S' - 30);
                if ((p.snake & (1 << snake_id)) == 0)
                {
                    next_snake |= (1 << snake_id);
                    next_step++;
                }
            }
            q.push(Node(next_x, next_y, next_step, next_snake, next_key));
        }
    }
}

int main()
{
    while (1)
    {
        cin >> n >> m;
        if (m == 0 && n == 0)
            break;
        while (!q.empty())
            q.pop();
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        int sx, sy;
        int cnt = 30;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'K')
                {
                    sx = i;
                    sy = j;
                }
                if (a[i][j] == 'S')
                {
                    a[i][j] += cnt;
                    cnt++;
                }
            }
        }
        q.push(Node(sx, sy, 1, 0, 0));
        ans = 1 << 10;
        bfs();
        if (ans == (1 << 10))
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
    return 0;
}