#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

int flag = 0;
int cmp(const void *a, const void *b){
    char *s1 = (char *)a;
    char *s2 = (char *)b;
    return strcmp(s1,s2);
}

void print_tab(int d);
void dfs(int d)
{
    char str[40];
    char files[40][40];
    int cnt = 0;
    while(1)
    {
        cin >> str;
        if(str[0] == 'f')
        {
            strcpy(files[cnt], str);
            cnt++;
        }
        if(str[0] == 'd')
        {
            print_tab(d+1);
            cout << str << endl;
            dfs(d+1);
        }
        if(str[0] == ']') break;
        if(str[0] == '*')
        {
            cin.ignore();
            char ch = cin.peek();
            if(ch == '#')
            {
                flag = 1;
            }
            break;
        }
    }

    //sort(files, files+cnt);二维数组不能用sort
    qsort(files, cnt, 40, cmp);
    for(int i=0;i<cnt;i++)
    {
        print_tab(d);
        cout << files[i] << endl;
    }
    return;
}

void print_tab(int d)
{
    for(int i=0;i<d-1;i++)
    {
        cout << "|" << "     ";
    }
}

int main()
{
    int case_num = 1;
    while (1)
    {
        char ch = cin.peek();
        if(ch == '#') break;
        cout << "DATA SET " << case_num << ":" << endl;
        case_num++;
        cout << "ROOT" << endl;
        dfs(1);
        if(!flag)
        {
            cout << endl;
        }
        if(flag) break;
    }
    system("pause");
    return 0;
}