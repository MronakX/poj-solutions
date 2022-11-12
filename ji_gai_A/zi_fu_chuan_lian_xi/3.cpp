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
        char * foodPairs [11][2] = {
  {"potato", "persimmon"},
  {"egg", "glucide"},
  {"onion", "honey"},
  {"bean-curd", "honey"},
  {"radish", "agaric"},
  {"taro", "banana"},
  {"pignut", "cucumber"},
  {"beef", "chestnut"},
  {"rabbit", "celery"},
  {"crab", "persimmon"},
  {"carp", "liquorice"}};

        int n;
        string food1, food2;
        cin >> n;
        cin.get();
        for(int i=0;i<n;i++)
        {
            int g=0;
            cin >> food1 >> food2; 
            for(int j=0;j<11;j++)
                    if((strcmp(food1.c_str(), foodPairs[j][0])) == 0 && (strcmp(food2.c_str(), foodPairs[j][1]) == 0))
                    {
                        g=1;
                        cout << "NO" << endl;
                    }
                    else if((strcmp(food2.c_str(), foodPairs[j][0])) == 0 && (strcmp(food1.c_str(), foodPairs[j][1]) == 0))
                    {
                        g=1;
                        cout << "NO" << endl;
                    }
                    else if((strcmp(food2.c_str(), foodPairs[j][1])) == 0 && (strcmp(food1.c_str(), foodPairs[j][0]) == 0))
                    {
                        g=1;
                        cout << "NO" << endl;
                    }
                    else if((strcmp(food1.c_str(), foodPairs[j][1])) == 0 && (strcmp(food1.c_str(), foodPairs[j][0]) == 0))
                    {
                        g=1;
                        cout << "NO" << endl;
                    }
            if(g==0)
            {
                cout << "YES" << endl;
            }
        }
        system("PAUSE");
        return 0;
    }