#include <iostream>
#include <iomanip>
using namespace std;
//a->1->c

void move(int n, char a, char b, char c, int num)
{
    if (n == 1)
    {
        cout << a << "->" << num << "->" << c << endl;
        return;
    }
    move(n - 1, a, c, b, num);
    cout << a << "->" << num + n - 1 << "->" << c << endl;
    move(n - 1, b, a, c, num);
    return;
}

int main()
{
    int n;
    char a, b, c;
    cin >> n >> a >> c >> b;
    move(n,a,b,c, 1);
    system("pause");
    return 0;
}