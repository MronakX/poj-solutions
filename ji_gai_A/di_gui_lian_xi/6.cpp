/*
        郭大卫
        1900012995
        
        19.10.09
        */

        #include <iostream>
        #include <iomanip>
        #include <cstring>
        #include <cmath>
        #include <algorithm>
        using namespace std;
        char str1[1000], str2[1000];
        bool match(char str1[], char str2[])
        {
            //cout << str1[0] << " " << str2[0] << endl;
            if(str1[0] != '?' && str1[0] != '*' && str1[0] != '\000')
            {
                if(str1[0] != str2[0])
                {
                    return false;
                }
                if(str1[0] == str2[0])
                {
                    if(match(str1+1,str2+1))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            if(str1[0] == '\000' && str2[0] == '\000')
            {
                return true;
            }
            if(str1[0] == '?')
            {
                if(str2[0] == '\000')
                {
                    return false;
                }
                else
                {
                    if(match(str1+1,str2+1))
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }   
                } 
            }
            if(str1[0] == '*')
            {
                if(str1[1] == '\000')
                {
                    return true;
                }
                else
                {
                    int g = 0;
                    for(int i=0;i<20;i++)
                    {
                        if(match(str1+1, str2+i))
                        {
                            g = 1;
                            break;
                        }
                    }
                    if(g)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                    
                }
                
            }
        }
        int main()
        {
            cin.getline(str1, 1000);
            cin.getline(str2, 1000);
            int len1 = strlen(str1);
            int len2 = strlen(str2);
            if(match(str1, str2))
            {
                cout << "matched" << endl;
            }
            if(!match(str1,str2))
            {
                cout << "not matched" << endl;
            }
            

            system("PAUSE");
            return 0;
        }