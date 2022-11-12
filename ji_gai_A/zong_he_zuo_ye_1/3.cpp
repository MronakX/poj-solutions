	/*
	郭大卫
	1900012995
    字符串排序	
	19.12.12
	*/
	#include <iostream>
	#include <iomanip>
	#include <cmath>
	#include <cstring>
	using namespace std;
	void mysort(char *name[], int n)//课件排序
	{
		char *t;
		for (int i=0; i<n-1; i++)
		{
			int k = i;
			for (int j=i+1; j<n; j++)
				if (strcmp(name[k], name[j]) > 0)
					k = j;
			if (k != i)
			{ 
				t = name[i]; 
				name[i] = name[k]; 
				name[k] = t; 
			}
		}
	}	
	void myprint(char *name[], int n)
	{
		for(int i=0; i<n; i++)
		{
			cout << name[i] << endl;
		}
	}
	int main()
	{
		char str[210][210] = {};
		int t;
		cin >> t;
		for(int i=0; i<t; i++)
		{
			int n;
			cin >> n;
			char *temp[210];
			cin.ignore();//吃掉\n
			for(int j=0; j<n; j++)
			{
				temp[j] = str[j];//temp指向str的对应一维数组
				cin.getline(str[j], 210);//一次getline一行			
			}
			mysort(temp, n);
			myprint(temp, n);
		}
		system("PAUSE");
		return 0;
	}