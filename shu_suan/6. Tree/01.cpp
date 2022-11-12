/*
郭大卫
1900012995
树的转换
20.11.26
*/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    string tag;
    TreeNode * son = NULL;
    vector<string> Siblings;
};
vector<TreeNode*> roots; 

bool is_last = 0;

void dfs(TreeNode* node, int d)
{
    while(1)
    {
        char line[40] = {};
        cin.getline(line, 40, '\n');

        if(strlen(line) == 0)
        {
            is_last = 1;
            break;
        }   
        if(line[0] == 'M')
        {
            TreeNode* tmp = new TreeNode;
            string str(line);
            tmp->tag = str;

            if(d == 0)
            {
                roots.push_back(tmp);
                dfs(tmp, 0);
                if(is_last)
                    return;
            }

            node->Siblings.push_back(str);
            continue;
        }
        else if(line[0] == '{')
        {
            char sonLine[40] = {};
            cin.getline(sonLine, 40, '\n');
            TreeNode* tmp = new TreeNode;
            string str(sonLine);
            tmp->tag = str;
            node->son = tmp;
            dfs(tmp, d + 1);
        }
        else if(line[0] == '}')
        {
            return;
        }
    }
    return;
}

bool founded = 0;
bool appear = 0;
void dfs_search(TreeNode* root, string src)
{
    //if(founded)
      //  return;
    if(root->tag == src)
    {
        appear = 1;
        for(auto i = root->Siblings.begin(); i != root->Siblings.end(); i++)
        {
            cout << *i;
            founded = 1;
        }
    }
    else 
    {
        bool flag = 0;
        for(auto i = root->Siblings.begin(); i != root->Siblings.end(); i++)
        {
            if(flag == 1)
            {
                cout << *i;
                founded = 1;
            }
            if(*i == src)
            {
                appear = 1;
                flag = 1;
            }
        }
    }
    if(root->son && !appear)
        dfs_search(root->son, src);
}

int main()
{
    int t;
    cin >> t;
    cin.get();
    while(t--)
    {
        roots.clear();
        char line[40] = {};
        cin.getline(line, 40, '\n');
        TreeNode* root = new TreeNode;
        string str(line);
        root->tag = str;
        roots.push_back(root);
        is_last = 0;
        dfs(root, 0);

        char src[40] = {};
        cin.getline(src, 40, '\n');
        string src_str(src);
        founded = 0;
        appear = 0;
        for(auto i = roots.begin(); i!=roots.end();i++)
        {
            if(appear)
                break;
            dfs_search(*i, src_str);
        }
        if(appear && !founded)
        {
            cout << "" << endl;
        }
        if(!appear)
            cout << "No" << endl;
        else
            cout << endl;
        cin.get();
        cin.get();
    }
    system("pause");
    return 0;
}