#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[110][300] = {};
    int b[110][300] = {};
    int t;
    int mi[110] = {};
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> mi[j];
            for(int k=0;k<mi[j];k++)
            {
                cin >> a[j][k] >> b[j][k];
            }
        }

        for(int i=0;i<n;i++)
        {
            cin >> mi[i];
            for(int k=0;k<mi[i];k++)
            {
                
            }
        }
    }
    system("pause");
    return 0;
}