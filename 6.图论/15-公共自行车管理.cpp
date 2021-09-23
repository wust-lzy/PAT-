#include <bits/stdc++.h>
using namespace std;

const int N = 510, inf = 1e8;
int cmax, n, sp, m;
int e[N][N], dis[N], weight[N];
int minneed = inf, minback = inf;
bool vis[N];
vector<int> pre[N], path, tempath;
void dfs(int v)
{
    tempath.push_back(v);
    if (v == 0){ //到达终点
        int need = 0, back = 0;
        for (int i = tempath.size() - 1; i >= 0; i--)
        {
            int id = tempath[i];
            if (weight[id] > 0)
                back += weight[id];
            else
            {
                if (back > (0 - weight[id]))
                    back += weight[id];
                else
                {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if (need < minneed)
        {
            minneed = need;
            minback = back;
            path = tempath;
        }
        else if (need == minneed && back < minback)
        {
            path = tempath;
            minback = back;
        }
        tempath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    tempath.pop_back();
}
void dijkstra()
{
    fill(dis, dis + 510, inf);
    dis[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        int u = -1;
        for (int j = 0; j <= n; j++)
        {
            if (!vis[j] && (u == -1 || dis[u] > dis[j]))
                u = j;
        }
        vis[u] = 1;
        for (int v = 0; v <= n; v++)
        {
            if (dis[v] > dis[u] + e[u][v])//保存最短路
            {
                dis[v] = dis[u] + e[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if (dis[v] == dis[u] + e[u][v])
                pre[v].push_back(u);
        }
    }
}
int main()
{
    fill(e[0], e[0] + 510 * 510, inf);
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
        weight[i] -= cmax / 2;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = min(e[a][b], c);
    }
    dijkstra();
    dfs(sp);
    printf("%d 0", minneed);
    for (int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minback);
    return 0;
}