/*
郭大卫
1900012995
建立有序链表
19.12.19
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct linker//建立链表
{
    int num;
    linker *next;
};

linker *createList()
{
    linker *ahead, *temp, *head = NULL;
    int k;
    char str;
    while(1)
    {
        cin >> k;
        str = cin.get();//get空格或换行符
        
        temp = new linker;
        temp -> num = k;
        if(head == NULL)//头仍为空，则temp为头
        {
            head = temp;
        }
        else//否则，将ahead和temp连接
        {
            ahead -> next = temp;
        }
        ahead = temp;//temp取代成为新的ahead
        if(str == '\n')//如果换行，则结束
        {
            break;
        }
    }
    if(head != NULL)//循环结束将temp指向NULL，防止temp中的next成为野指针
    {
        temp -> next = NULL;
    }
    return head;//返回头
}

void mysort(linker *head)
{
    linker *temp, *ahead, *tail = NULL;
    while(head != tail)//外层循环head，当头不为空，则尚未结束
    {
        ahead = head;
        temp = ahead -> next;
        while(temp != tail)//内层循环temp
        {
            if(ahead -> num > temp ->num)//交换排序
            {
                int t = ahead -> num;
                ahead -> num = temp -> num;
                temp -> num = t;
            }
            ahead = temp;
            temp = temp -> next;
        }
        tail = ahead;
    }
}

void printList(linker *head)//输出链表
{
    linker *temp;
    cout << head -> num;
    temp = head -> next;
    while(temp != NULL)
    {
        cout << " " << temp -> num;
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        linker *head;
        head = createList();
        mysort(head);
        printList(head);
    }
    system("PAUSE");
	return 0;
}