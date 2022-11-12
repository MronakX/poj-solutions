#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
//每个操作最多4次
//4^9 = 262144
/*
A 124
B 1235
C 236
D 1457
E 13579
F 3569
G 478
H 5789
I 689
*/
int a[10] = {};
int ori[10] = {};
int op[10] = {};
int ans[10] = {};
int minsum = 40;
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        cin >> ori[i];
    }
    for (int op1 = 0; op1 < 4; op1++)
        for (int op2 = 0; op2 < 4; op2++)
            for (int op3 = 0; op3 < 4; op3++)
                for (int op4 = 0; op4 < 4; op4++)
                    for (int op5 = 0; op5 < 4; op5++)
                        for (int op6 = 0; op6 < 4; op6++)
                            for (int op7 = 0; op7 < 4; op7++)
                                for (int op8 = 0; op8 < 4; op8++)
                                    for (int op9 = 0; op9 < 4; op9++)
                                    {
                                        memcpy(a, ori, sizeof(ori));
                                        op[1] = op1;
                                        op[2] = op2;
                                        op[3] = op3;
                                        op[4] = op4;
                                        op[5] = op5;
                                        op[6] = op6;
                                        op[7] = op7;
                                        op[8] = op8;
                                        op[9] = op9;
                                        a[1] = (a[1] + op[1] + op[2] + op[4]) % 4;
                                        a[2] = (a[2] + op[1] + op[2] + op[3] + op[5]) % 4;
                                        a[3] = (a[3] + op[2] + op[3] + op[6]) % 4;
                                        a[4] = (a[4] + op[1] + op[4] + op[5] + op[7]) % 4;
                                        a[5] = (a[5] + op[1] + op[3] + op[5] + op[7] + op[9]) % 4;
                                        a[6] = (a[6] + op[3] + op[5] + op[6] + op[9]) % 4;
                                        a[7] = (a[7] + op[4] + op[7] + op[8]) % 4;
                                        a[8] = (a[8] + op[5] + op[7] + op[8] + op[9]) % 4;
                                        a[9] = (a[9] + op[6] + op[8] + op[9]) % 4;
                                        if (a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 && a[6] == 0 && a[7] == 0 && a[8] == 0 && a[9] == 0)
                                        {
                                            int sum = 0;
                                            sum += op[1] + op[2] + op[3] + op[4] + op[5] +op[6] +op[7] +op[8] +op[9];
                                            if(sum < minsum)
                                            {
                                                minsum = sum;
                                                memcpy(ans, op, sizeof(op));
                                            }
                                        }
                                    }

    int flag = 1;
    for(int i=1;i<=9;i++)
    {
        while(ans[i])
        {
            if(!flag)
            {
                cout << " " << i;
                ans[i]--;
            }
            else
            {
                cout << i;
                ans[i]--;
                flag = 0;
            }
        }
    }
    system("pause");
    return 0;
}