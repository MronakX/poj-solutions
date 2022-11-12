    /*
    郭大卫
    1900012995
    
    19.10.09
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int n;
        string word;
        cin >> n;
        cin.get();
        int sum = 0;
        cin >> word;
        cout << word;
        sum += strlen(word.c_str());
        for(int i=1;i<n;i++)
        {
            cin >> word;
            int length = strlen(word.c_str());
            sum += length+1;
            if(sum > 80)
            {
                cout << endl << word;
                sum = 0;
                sum += length;
                continue;
            }
            cout << " " << word;

        }
        
        system("PAUSE");
        return 0;
    }