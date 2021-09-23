#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 35;
int post[N], in[N];
int n, cnt = 0;
map<int, int> tree;
struct node
{
    int val;
    node *left;
    node *right;
    node(){}
};
node* build(int root,int st,int ed)//根据中序和后序建树
{
    if(st>ed)
        return nullptr;
    int k = st;
    while(k<ed&&in[k]!=post[root])
        k++;
    node *t = new node();
    t->val = in[k];
    t->left=build(root - 1 - (ed - k), st, k - 1);
    t->right=build(root - 1, k + 1, ed);
    return t;
}
void dfs(node *root,int u)//map存储层序遍历
{
    tree[u] = root->val;
    if (root->left != nullptr)
        dfs(root->left, 2 * u);
    if(root->right!=nullptr)
        dfs(root->right, 2 * u + 1);
}
int main()
{
    FAST;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> post[i];
    for (int i = 0; i < n;i++)
        cin >> in[i];
    node *root=build(n - 1, 0, n - 1);
    dfs(root, 1);
    int fir = 1;
    for (auto &e : tree){
        if(fir){
            cout << e.second;
            fir = 0;
        }
        else
            cout << " " << e.second;
    }

    return 0;
}