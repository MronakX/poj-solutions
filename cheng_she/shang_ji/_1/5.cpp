#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int p, e, i, d;
    cin >> p >> e >> i >> d;
    int j = 0;
    for(j=d+1;(j-p)%23!=0; j++);
    for(; (j-e)%28!=0;j+=23);
    for(;(j-i)%33!=0; j+=23*28);
    cout << j-d << endl;
    system("pause");
    return 0;
}