#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n, cnt;
int l[N], r[N];//左右孩子
int in[N], w[N];//中序，层序
vector<int> ans;
void dfs(int u) //中序遍历建树
{
    if(u==-1)
        return;
    dfs(l[u]);//左
    w[u] = in[cnt++];//根
    dfs(r[u]); //右
}

void bfs()
{
    queue<int> q;
    q.push(0);
    while(!q.empty())//bfs保存层序遍历结果
    {
        int t = q.front();
        q.pop();
        ans.push_back(w[t]);
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
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)  //左右孩子
        cin >> l[i] >> r[i];
    for (int i = 0; i < n;i++)//中序结果
        cin >> in[i];
    sort(in, in + n);//中序
    dfs(0);
    bfs();
    return 0;
}