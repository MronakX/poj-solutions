/*
郭大卫
1900012995
多项式加法 stl(map)
20.09.29
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        map<int, int, greater<int> > a;
        while(1)
        {
            int num1, num2;
            cin >> num1 >> num2;
            if(num2 < 0)
                break;
            if(!a[num2])
            {
                a[num2] = num1;
            }
            else
            {
                a[num2] += num1;
            }
        }
        while(1)
        {
            int num1, num2;
            cin >> num1 >> num2;
            if(num2 < 0)
                break;
            if(!a[num2])
            {
                a[num2] = num1;
            }
            else
            {
                a[num2] += num1;
            }
        }
        for(auto i = a.begin(); i!= a.end(); i++)
        {
            if(i->second != 0)
                cout << "[ " << i->second << " " << i->first << " ] ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}