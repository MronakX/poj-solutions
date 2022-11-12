/*
郭大卫
1900012995
表达式·表达式树·表达式求值 
20.11.28
*/

#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <string.h>

using namespace std;

int n;
stack<char> s;
vector<char> post;
char str[1000] = {};
int cnt = 0;
int dict[30] = {};
struct Tree_Node
{
    char c;
    int num;
    int h = 1;
    Tree_Node *l = NULL, *r = NULL;
    Tree_Node *p = NULL;
    //Tree_Node(char cc, Tree_Node * ll = NULL, Tree_Node *rr = NULL, Tree_Node *pp = NULL):c(cc), l(ll), r(rr), p(pp){}
};

bool check_prior(char a, char b)//a<=b true
{
    if(a == '+' || a == '-')
        return true;
    else
    {
        if(b == '+' || b == '-')
            return false;
        else
            return true;
    }
    
}

void gen_post()
{
    cin.getline(str, 900);
    int cnt = 0;
    while(str[cnt] != 0)
    {
        if(str[cnt] <= 'z' && str[cnt] >= 'a')
        {
            post.push_back(str[cnt]);
            cnt++;
            continue;
        }
        
        if(str[cnt] == '(')
        {
            s.push(str[cnt]);
            cnt++;
        }
        else if(str[cnt] != ')')
        {
            while(1)
            {
                if(!s.empty() && s.top() != '(' && check_prior(str[cnt], s.top()))
                {
                    post.push_back(s.top());
                    s.pop();
                }
                else
                {
                    s.push(str[cnt]);
                    cnt++;
                    break;
                }
            }
        }
        else
        {
            while(s.top() != '(')
            {
                post.push_back(s.top());
                s.pop();
            }
            s.pop();
            cnt++;
        }
    }
    while(!s.empty())
    {
        post.push_back(s.top());
        s.pop();
    }

    for(auto i = post.begin(); i != post.end(); i++)
    {
        cout << *i;
    }
    cout << endl;
}
stack<Tree_Node*> ans;
void gen_tree()
{
    for(auto i = post.begin(); i!=post.end(); i++)
    {
        if(*i <= 'z' && *i >= 'a')
        {
            Tree_Node *tmp = new Tree_Node;
            tmp->c = *i;
            tmp->num = dict[*i-'a'];
            ans.push(tmp);
            continue;
        }
        if((*i == '+') || (*i == '-') || (*i == '*') || (*i == '/'))
        {
            Tree_Node * tmp_root = new Tree_Node;
            Tree_Node * tmp_r = ans.top();
            ans.pop();
            Tree_Node * tmp_l = ans.top();
            ans.pop();

            tmp_root->c = *i;
            tmp_root->l = tmp_l;
            tmp_root->r = tmp_r;
            int num1 = tmp_l->num;
            int num2 = tmp_r->num;
            switch (*i)
            {
                case '+':
                    tmp_root->num = num1 + num2; 
                    break;
                case '-':
                    tmp_root->num = num1 - num2; 
                    break;
                case '*':
                    tmp_root->num = num1 * num2; 
                    break;
                case '/':
                    tmp_root->num = num1 / num2; 
                    break;
                default:
                    break;
            }
            tmp_root->h = max(tmp_l->h, tmp_r->h) + 1;
            ans.push(tmp_root);
        }
    }
}

int pow2[29] = {1};
char graph[200][200] = {};
void print_tree(int h, int x, int y, Tree_Node* root)
{
    graph[x][y] = root->c;
    if(root->l != NULL)
    {
        graph[x+1][y-1] = '/';
        print_tree(h-1, x+2, y - pow2[h-2], root->l);
    }
    if(root->r != NULL)
    {
        graph[x+1][y+1] = '\\';
        print_tree(h-1, x+2, y + pow2[h-2], root->r);
    }
}

int main()
{
    gen_post();
    int n;
    cin >> n;
    while(n--)
    {
        char ch;
        int num;
        cin >> ch >> num;
        dict[ch-'a'] = num;
    }  
    for(int i=1; i<29; i++)
    {
        pow2[i] = pow2[i-1] * 2;
    }
    gen_tree();
    memset(graph, ' ', sizeof(graph));
    int h0 = ans.top()->h;
    int ans0 = ans.top()->num;
    print_tree(h0, 0, pow2[h0-1]-1, ans.top());
    for(int i=0; i < 2*h0 - 1; i++)
    {
        int j = 199;
        while(graph[i][j] == ' ')
        {
            graph[i][j] = 0;
            j--;
        }
    }
    for(int i=0; i<2*h0-1; i++)
    {
        cout << graph[i] << endl;
    }
    cout << ans0 << endl;
    system("pause");
    return 0;
}