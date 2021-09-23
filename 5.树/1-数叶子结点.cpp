#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 110;

int n,m;
int h[N], e[N], ne[N], idx;
int cnt[N];//每一层叶子结点的数量
int max_lev;
void add(int a, int b) //插入一条a到b的边
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u,int depth)
{
    if(h[u]==-1)//说明数叶子节点
    {
        cnt[depth]++;
        max_lev = max(max_lev, depth);
    }
    for (int i = h[u]; ~i;i=ne[i])
        dfs(e[i], depth + 1);
}
int main()
{
    FAST;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m;i++)
    {
        int id, k;
        cin >> id >> k;
        while(k--)
        {
            int son;
            cin >> son;
            add(id, son);
        }
    }
    dfs(1, 0);//根结点，层数
    for (int i = 0; i <= max_lev;i++)
    {
        cout << cnt[i];
        if(i!=max_lev)
            cout << ' ';
    }
        return 0;
}