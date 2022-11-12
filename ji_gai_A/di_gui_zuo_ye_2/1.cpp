        /*
        郭大卫
        1900012995
        放苹果问题
        19.11.13
        */
        #include <iostream>
        #include <iomanip>
        #include <cmath>
        #include <cstring>
        #include <algorithm>
        using namespace std;
        int apple(int m, int n)
        {
            if(m < 0 || n <= 0)
            {
                return 0;
            }
            if(n == 1 || m == 0 )
            {
                return 1;
            }
            return apple(m,n-1) + apple(m-n,n);
            //把m个苹果放进n个盘子，分为两种情况，有空盘子和没空盘子
            //有空盘子，则减少一个盘子，将m个苹果放进n-1个盘子；
            //无空盘子，则先在n个盘子里各放置1个苹果，剩余m-n个苹果；递归直到m-n小于n，则可转化为第一种情况。
        }

        int main()
        {
            int num, n, m;//num数据组数。
            cin >> num;
            for(int k=0; k<num; k++)
            {
                cin >> m >> n;
                cout << apple(m,n) << endl;
            }
            return 0;
        }