#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=6; i<=n;i++)
    {
        for(int a=2;a<i;a++)
        {
            for(int b=a;b<i;b++)
            {
                for(int c=b;c<i;c++)
                {
                    if((a*a*a + b*b*b + c*c*c) == i*i*i)
                    {
                        cout << "Cube = " << i << ", Triple = (" << a << "," << b << "," << c << ")" << endl;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}