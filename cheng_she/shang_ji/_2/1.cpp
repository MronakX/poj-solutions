#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, na, nb;
    int a[1100] = {};
    int b[1100] = {};
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<nb;i++)
    {
        cin >> b[i];
    }
    int wina = 0, winb = 0;
    for(int i=0;i<n;i++)
    {
        int numa = i%na;
        int numb = i%nb;
        int movea = a[numa];
        int moveb = b[numb];
        if(movea == 0 && moveb == 2)
        {
            wina++;
            continue;
        }
        if(movea == 2 && moveb == 5)
        {
            wina++;
            continue;
        }
        if(movea == 5 && moveb == 0)
        {
            wina++;
            continue;
        }

        if(moveb == 5 && movea == 0)
        {
            winb++;
            continue;
        }
        if(moveb == 0 && movea == 2)
        {
            winb++;
            continue;
        }
        if(moveb == 2 && movea == 5)
        {
            winb++;
            continue;
        }
    }

    if(wina > winb) cout << "A" << endl;
    else if (wina == winb) cout << "draw" << endl;
    else if(wina < winb) cout << "B"<< endl;
    system("pause");
    return 0;
}