        /*
        郭大卫
        1900012995
        有理数树
        19.11.13
        */
        #include <iostream>
        #include <iomanip>
        #include <cstring>
        using namespace std;
        //注意到，每一个节点的位置相当于上一个节点的2倍、或2倍加1；左枝为前者，右枝为后者；
        int find(int x, int y)//x为分子，y为分母
        {
            if(x == y)//当分子等于分母，则只可能为1/1，位置为1
            {
                return 1;
            }
            if(x > y)//分子大于分母，则这个分数是从上一个节点延伸出的右枝，位置为2*上一个节点的位置+1；
            {
                return 2 * find(x-y, y) + 1;
            }
            if(x < y)//分母大于分子，则为左枝，位置为上一个节点*2
            {
                return 2 * find(x, y-x);
            }
        }

        int main()
        {
            int n, x, y;
            cin >> n;
            for(int i=0; i<n; i++)
            {
                cin >> x >> y;
                cout << find(x,y) << endl;
            }
            return 0;
        }