#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
    char lock[40] = {};
    char temp[40] = {};
    char target[40] = {};
    int op[40] = {};
    int ans = 40;
    cin >> lock >> target;
    int len = strlen(lock);
    for (int j = 0; j <= 1; j++)
    {
        op[0] = j;
        memcpy(temp, lock, sizeof(lock));
        int sum = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (op[i] == 0 & temp[i] == target[i])
            {
                op[i + 1] = 0;
                continue;
            }
            if (op[i] == 0 & temp[i] != target[i])
            {
                op[i + 1] = 1;
                continue;
            }
            if (op[i] == 1 & temp[i] == target[i])
            {
                if (temp[i + 1] == '0')
                    temp[i + 1] = '1';
                else
                    temp[i + 1] = '0';
                op[i + 1] = 1;
                continue;
            }
            if (op[i] == 1 & temp[i] != target[i])
            {
                if (temp[i + 1] == '0')
                    temp[i + 1] = '1';
                else
                    temp[i + 1] = '0';
                op[i + 1] = 1;
                op[i + 1] = 0;
                continue;
            }
        }
        if ((temp[len - 1] == target[len - 1] && op[len - 1] == 0) || (temp[len - 1] != target[len - 1] && op[len - 1] == 1))
        {
            for (int i = 0; i < len; i++)
            {
                if (op[i])
                    sum++;
            }
            ans = min(sum, ans);
        }
    }
    if(ans == 40)
    {
        cout << "impossible" << endl;
    }
    else
        cout << ans << endl;
    system("pause");
    return 0;
}