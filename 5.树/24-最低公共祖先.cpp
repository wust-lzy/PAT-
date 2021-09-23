#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 10100;
int in[N], pre[N];
int n, q;
unordered_set<int> exist;//记录每个点是否存在
unordered_map<int, int> vis;//记录中序每个节点值的位置

struct node{    //定义结点
    int val;
    node *left;
    node *right;
};

node *build(int root,int st,int ed){//前序和中序转后序
    if(st>ed)
        return nullptr;
    int k = vis[pre[root]];
    node *t = new node();
    t->left = build(root + 1, st, k - 1);
    t->right = build(root + 1 + (k - st), k + 1, ed);
    t->val = pre[root];
    return t;
}

node* dfs(node *root,int a,int b){  //寻找最近公共祖先算法
    if(!root)
        return nullptr;
    if(root->val==a||root->val==b)
        return root;
    node *l = dfs(root->left, a, b);
    node *r = dfs(root->right, a, b);
    if(l&&r)
        return root;
    else if(l)
        return l;
    return r;
}
int main()
{
    cin >> q >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> pre[i];
        exist.insert(pre[i]);
    }
    memcpy(in, pre, sizeof pre);
    sort(in, in + n);
    for (int i = 0; i < n; i++)
        vis[in[i]] = i;
    node *root = build(0, 0, n - 1);
    while(q--){
        int a, b;
        cin >> a >> b;
        if(!exist.count(a)||!exist.count(b)){   //有不存在的结点
            if(!exist.count(a)&&!exist.count(b)){
                printf("ERROR: %d and %d are not found.\n",a,b);
            }
            else if(!exist.count(a))
                printf("ERROR: %d is not found.\n", a);
            else
                printf("ERROR: %d is not found.\n", b);
        }
        else{
            node *ans = dfs(root, a, b);//找到祖先
            if(ans->val==a)
                printf("%d is an ancestor of %d.\n", a, b);
            else if(ans->val==b)
                printf("%d is an ancestor of %d.\n", b, a);
            else
                printf("LCA of %d and %d is %d.\n", a, b, ans->val);
        }
    }
    return 0;
}