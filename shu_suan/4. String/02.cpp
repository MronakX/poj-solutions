/*
郭大卫
1900012995
2:合格的字符串 大小写转换+模拟
20.10.19
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char cap2low(char src)
{
	if(src >= 'a' && src <= 'z')
	{
		return src - 'a' + 'A';
	}
	if(src >= 'A' &&  src <= 'Z')
	{
		return src - 'A' + 'a';
	}
	return src;
}

bool check(string tmp, string pat)
{

	int lent = tmp.size();
	int it = 0, ip = 0;
	for(it = 0; it < lent; )
	{
		if(tmp[it] == pat[ip] || tmp[it] == cap2low(pat[ip]))
		{
			it++;
			ip++;
		}
		else if(tmp[it] == '[')
		{
			int flag = 0;
			it++;
			while(tmp[it] != ']')
			{
				if(tmp[it] == pat[ip] || tmp[it] == cap2low(pat[ip]))
				{
					flag = 1;
					break;//important
				}
				it++;
			}
			while(tmp[it] != ']')
				it++;
			//it->']'
			it++;
			if(flag)
				ip++;
			else
				return false;
		}
		else
			return false;
	}
	if(it == lent)
		return true;
	return false;
}

int main()
{
	vector <string> v;

	int n;
	cin >> n;
	while(n--)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}
	string tmp;
	cin >> tmp;
	int cnt = 0;
	for(auto i = v.begin(); i!=v.end();i++)
	{
		cnt++;
		if(check(tmp, *i))
		{
			cout << cnt << " " << *i << endl;
		}
	}
    system("pause");
    return 0;
}