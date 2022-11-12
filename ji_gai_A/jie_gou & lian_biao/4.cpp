/*
郭大卫
1900012995
删除链表中的元素
19.12.20
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

struct linker
{
    int num;
    linker *next;
};

linker *createList(int n)//同上一题
{
    linker *ahead, *temp, *head = NULL;
    int k;
    for(int i=0;i<n;i++)
    {
        cin >> k;
        temp = new linker;
        temp -> num = k;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            ahead -> next = temp;
        }
        ahead = temp;
    }
    if(head != NULL)
    {
        temp -> next = NULL;
    }
    return head;
}

void printList(linker *head)//同上一题
{
    linker *temp;
    cout << head->num;
    temp = head -> next;
    while(temp!=NULL)
    {
        cout << " " << temp -> num;
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    linker *head;
    int n;
    cin >> n;
    head = createList(n);
    int k;
    cin >> k;
    linker *temp, *nextone;
    temp = head;
    while(temp -> next != NULL && head -> next != NULL)
    {
        if(head -> num == k)//当head为k
        {
            linker *tool = head;
            head = head -> next;//head被下一个链表取代
            delete tool;//删除原有的head
            continue;
        }
        nextone = temp -> next;//当head不为k，则定义一个nextone，指向Temp的下一个
        if(nextone != NULL && nextone->num == k)//当nextone为k
        {
            temp -> next = temp -> next -> next;//temp跳过nextone,指向nextone的下一个
            delete nextone;//删除nextone
        }
        else//否则向后继续遍历
        {
            temp = temp -> next;
        }
    }
    printList(head);
    system("PAUSE");
	return 0;
}