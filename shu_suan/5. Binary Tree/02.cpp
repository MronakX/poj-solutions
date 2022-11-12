#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int mid[70000];
int post[70000];

class BiTreeNode
{
    public:
    int tag;
    BiTreeNode* left = NULL;
    BiTreeNode* right = NULL;
};

BiTreeNode* dfs(int mid_st, int mid_end, int post_st, int post_end)
{
    if(mid_st > mid_end)
        return NULL;
    BiTreeNode *root = new BiTreeNode;
    root->tag = post[post_end];
    for(int i = mid_st; i <= mid_end; i++)
    {
        if(root->tag == mid[i])
        {   //cout << root->tag << " ";
            root->left = dfs(mid_st, i-1, post_st, post_st+i-mid_st-1);
            //if(root->left)
            //    cout << root->left->tag << " ";
            root->right = dfs(i+1, mid_end, post_st+i-mid_st, post_end - 1);
            //if(root->right)
            //   cout << root->right->tag;
                
        }
    }
    return root;
}

void print(BiTreeNode* root)
{
    if(!root)
        return;
    cout << root->tag << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    char ch;
    int num;
    int cnt = 0;
    while(cin >> num)
    {
        mid[cnt++] = num;
        if(cin.get() == '\n')
            break;
    }
    cnt = 0;
    while(cin >> num)
    {
        post[cnt++] = num;
        if(cin.get() == '\n')
            break;
    }
    cnt--;
    BiTreeNode* root = dfs(0, cnt, 0 ,cnt);
    print(root);
    return 0;
}