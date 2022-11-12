#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double dfs()
{
    char str[10]={};
    cin >> str;
    if(str[0] == '+')
        return dfs() + dfs();
    if(str[0] == '-')
        return dfs() - dfs();
    if(str[0] == '*')
        return dfs() * dfs();
    if(str[0] == '/')
        return dfs() / dfs();
    return atof(str);
}

int main()
{
    cout << fixed << setprecision(6) << dfs() << endl;
    system("pause");
    return 0;
}