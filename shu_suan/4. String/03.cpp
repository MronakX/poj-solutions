/*
郭大卫
1900012995
3:字符串乘方 kmp 同“前缀中的周期题目”
20.10.19
*/

#include <iostream>
#include <string.h>
#include <vector>
#include <cstdio>

using namespace std;

int Next[1000100] = {};
char str[1000100] = {};
void kmp_pre()
{
	int i = 0, k = -1;
	int len = strlen(str);
	Next[0] = -1;
	while(i < len)//需next[len-1],故i应多指一位
	{
		while(k>=0 && str[k] != str[i])
			k = Next[k];
		i++;
		k++; 
		if (str[k] == str[i])   
              Next[i] = Next[k];  
		Next[i] = k;
	}
}

int main()
{
	while(1)
	{
		memset(str, 0, sizeof(str));
		memset(Next, 0, sizeof(Next));
		scanf("%s", str);//scanf不兼容string类
		if(str[0] == '.')
			break;
		kmp_pre();
		int len = strlen(str);
		if(len % (len - Next[len]) == 0)//数归证明
			printf("%d\n", len / (len - Next[len]));
		else
			printf("1\n");
	}	
    system("pause");
    return 0;
}