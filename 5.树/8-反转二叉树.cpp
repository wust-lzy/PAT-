#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, root;
int l[N], r[N]; //左右孩子
bool hasfather[N];
vector<int> in;
void dfs(int u)
{
    if(u==-1)
        return;
    swap(l[u], r[u]);
    dfs(l[u]);
    dfs(r[u]);
}

void bfs()//层序遍历
{
    vector<int> ans;
    queue<int> q;
    q.push(root);
    while(!q.empty())//bfs保存层序遍历结果
    {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        if (l[t] != -1)
            q.push(l[t]);
        if(r[t]!=-1)
            q.push(r[t]);
    }
    for (int i = 0; i < n;i++){
        cout << ans[i];
        if(i!=n-1)
            cout << " ";
    }
    puts("");
}
void inorder(int u)//中序
{
    if(l[u]!=-1)
        inorder(l[u]);
    in.push_back(u);
    if(r[u]!=-1)
        inorder(r[u]);
}
int main()
{
    string a, b;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a >> b;
        if(a=="-")
            l[i] = -1;
        else{
            l[i] = stoi(a);
            hasfather[l[i]] = 1;
        }
        if(b=="-")
            r[i] = -1;
        else{
            r[i] = stoi(b);
            hasfather[r[i]] = 1;
        }
    }
    for (int i = 0; i < n;i++)
    if(!hasfather[i]){
        root = i;
        break;
    }
    dfs(root);
    bfs();
    inorder(root);
    for (int i = 0; i < n;i++){
        cout << in[i];
        if(i!=n-1)
            cout << " ";
    }
        return 0;
}