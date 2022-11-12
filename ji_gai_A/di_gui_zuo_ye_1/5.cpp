        /*
        郭大卫
        1900012995
        
        19.10.09
        */

        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
        int eliminate(int n)
        {
            if(n == 1)
            return 1;
            if(n == 2)
            return 1;
            if(n == 3)
            return 2;
            if(n==4)
            return 3;
            if(n==5)
            return 5;
            if(n>5)
            return eliminate(n-1) + eliminate(n-3) + eliminate(n-5);
        }
        int main()
        {
            int n;
            cin >> n;
            cout << eliminate(n) << endl;
            system("PAUSE");
            return 0;
        }