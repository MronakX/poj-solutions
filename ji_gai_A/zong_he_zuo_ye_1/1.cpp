/*
郭大卫
1900012995
2013年诺贝尔生理学奖中的基因模式识别
19.12.11
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	char str[1000] = {};
	char templ1[14] = {'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T'};//13个T
	char templ2[14] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};//13个A，用来strstr
	cin >> n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		memset(str, 0, sizeof(str));
		cin.getline(str, 1000);
		if(strstr(str, templ1) !=NULL || strstr(str, templ2) !=NULL)//包含连续13个A或13个T
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	system("PAUSE");
	return 0;
}