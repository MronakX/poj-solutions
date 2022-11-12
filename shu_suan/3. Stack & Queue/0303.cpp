/*
郭大卫
1900012995
堆栈基本操作 stack基本操作，注意非法出列判断
20.10.09
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<string> q_number[11];
	queue<string> q_letter[5];
	queue<string> ans;
	while(n--)
	{
		string str;
		cin >> str;
		int y = str[1] - '0';
		q_number[y].push(str);
	}
	for(int i=1;i<=9;i++)
	{
		cout << "Queue" << i << ":";
		while(!q_number[i].empty())
		{
			string card = q_number[i].front();
			cout << card << " ";
			q_letter[card[0]-'A' + 1].push(card);
			q_number[i].pop();
		}
		cout << endl;
	}
	for(int i=1;i<=4;i++)
	{
		cout << "Queue" << char(i-1+'A') << ":";
		while(!q_letter[i].empty())
		{
			cout << q_letter[i].front() << " ";
			ans.push(q_letter[i].front());
			q_letter[i].pop();
		}
		cout << endl;
	}
	while(!ans.empty())
	{
		cout << ans.front() << " ";
		ans.pop();
	}
    system("pause");

    return 0;
}