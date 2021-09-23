#include <bits/stdc++.h>
using namespace std;

int post[35], in[35], n;
unordered_map<int, int> vis;//哈希表优化，记录中序每个元素的位置
struct node
{
    int data;
    node *left, *right;
};
node* build(int root, int start, int end)//建树
{
    if (start > end)
        return nullptr;
    int i = vis[post[root]];
    node *t = new node();
    t->data = in[i];
    t->left=build(root - (end - i) - 1, start, i - 1);
    t->right=build(root - 1, i + 1, end);
    return t;
}
void bfs(node *root)//z字型遍历
{
    queue<node *> q;
    q.push(root);
    vector<vector<int> > all;
    vector<int> ans;
    while (!q.empty())
    {
        vector<int> temp;
        int k = q.size();
        for (int i = 0; i < k;i++){
            node *t = q.front();
            q.pop();
            temp.push_back(t->data);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        all.push_back(temp);
    }
    for (int i = 0; i < all.size();i+=2)//奇数层反转
        reverse(all[i].begin(), all[i].end());
    for(auto&e:all){
        for(int &t:e)
            ans.push_back(t);
    }
    for (int i = 0; i < n;i++){
        cout << ans[i];
        if(i!=n-1)
            cout << " ";
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> in[i];
        vis[in[i]] = i;
    }
    for (int i = 0; i < n; i++)
        cin >> post[i];
    node* root=build(n - 1, 0, n - 1);
    bfs(root);
    return 0;
}