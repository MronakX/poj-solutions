    /*
    郭大卫
    1900012995
    校门外的树
    19.10.09
    */

    #include <iostream>
    #include <iomanip>
    #include <math.h>
    #include <string.h>
    using namespace std;
    int main()
    {
        int n, hour, minute, sec, year, month, day, time;
        int sum1 = 0, sum2 = 0;
        int firsttime;
        int been[50][50]={0,0};//0没打过卡，1为打过早卡，2打过第一次晚卡，3晚卡成功,不再接受当日打卡
        cin >> n;
        for(int j=0;j<30;j++)
            for(int k=0;k<40;k++)
            {
                been[j][k]=0;
            }
        for(int i=1; i<=n; i++)
        {
            cin >> hour >> minute >> sec >> year >> month >> day;
            time = hour*3600 + minute * 60 + sec;
            if(time >= 25200 && time <= 30600 )
            {
                if(been[month][day]==0)
                {
                    been[month][day]=1;
                    sum1 ++;
                }
            }

            if(time >= 57600 && time <= 77400)
            {
                if(been[month][day]==3)
                {
                    continue;
                }
                if(been[month][day]==2)
                {
                    if((time - firsttime)>=1800)
                    {
                        been[month][day] = 3;
                        sum2++;
                    }
                }
                if(been[month][day]==1 || been[month][day]==0)
                {
                    been[month][day] = 2;
                    firsttime = time;
                }
            }
        }
        cout << max(10-sum1,0) << " " << max(20-sum2,0) << endl;
        system("PAUSE");
        return 0;
    }