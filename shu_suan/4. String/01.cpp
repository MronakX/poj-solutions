/*
郭大卫
1900012995
1:去除C程序中的注释 模拟
20.10.19
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


using namespace std;
int main()
{
	char line[220] = {};
	string str, ans;
	while(cin.getline(line, 220))
	{
		int cnt = 0;
		while(line[cnt] != 0)
		{
			str += line[cnt++];
		}
		str += '\n';//important
	}	

	int flag_anno = 0, flag_str = 0;
	int cnt = 0;
	int maxlen = str.length() - 1;//important! or cnt+1越界
	int flag = 0;
	if(str[0] == '"')//只检查cnt+1，故特判
		flag_str = 1;
	while(1)
	{
		if(flag)
		{
			break;
		}
		if(flag_anno)
		{
			while(1)
			{
				if(cnt >= maxlen)//lastchar is \n
				{
					flag = 1;
					break;
				}
				if(str[cnt] == '*' && str[cnt+1] == '/')
				{
					cnt += 2;
					flag_anno = 0;
					break;
				}
				else
					cnt++;
			}
		}
		else if(flag_str)
		{
			while(1)
			{
				if(cnt >= maxlen)
				{
					flag = 1;
					break;
				}
				if(str[cnt] != '\\' && str[cnt+1] == '"')
				{
					ans += str[cnt];
					ans += str[cnt+1];
					cnt += 2;
					flag_str = 0;
					break;
				}
				else
				{
					ans += str[cnt];
					cnt++;
				}
			}
		}
		else 
		{
			while(1)
			{
				if(cnt >= maxlen)
				{
					flag = 1;
					break;
				}
				if(str[cnt] == '/' && str[cnt+1] == '*')
				{
					flag_anno = 1;
					cnt+=2;
					break;
				}
				if(str[cnt] != '\\' && str[cnt+1] == '"')//注意str[0] = '"'
				{
					ans += str[cnt];
					ans += str[cnt+1];
					flag_str = 1;
					cnt+=2;
					break;
				}
				else
				{
					ans += str[cnt];
					cnt++;
				}
			}
		}
	}
	cout << ans << endl;
    system("pause");
    return 0;
}