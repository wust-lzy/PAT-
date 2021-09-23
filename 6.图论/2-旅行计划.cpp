#include <bits/stdc++.h>
using namespace std;

const int N = 510, inf = 1e8;

int n,m,st,ed;
int cost[N],dis[N], pre[N];//pre数组保存到达当前点的前一个点
int e[N][N], c[N][N];//边权，花费

bool vis[N];
void dijkstra()//dijkstra
{
    fill(dis, dis + N, inf);
    fill(cost, cost + N, inf);
    dis[st] = 0, cost[st] = 0;
    for (int i = 0; i < n;i++){
        int u = -1;
        for (int j = 0; j < n;j++){
            if(!vis[j]&&(u==-1||dis[j]<dis[u]))
                u = j;
        }
        vis[u] = 1;
        for (int v = 0; v < n;v++){
            if(dis[v]>dis[u]+e[u][v]){
                dis[v] = dis[u] + e[u][v];
                cost[v] = cost[u] + c[u][v];
                pre[v] = u;
            }
            else if(dis[v]==dis[u]+e[u][v]){
                if(cost[v]>cost[u]+c[u][v]){
                    cost[v] = cost[u] + c[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> st >> ed;
    fill(e[0], e[0] + N * N, inf);
    fill(c[0], c[0] + N * N, inf);
    while(m--){
        int a, b, x,y;
        cin >> a >> b >> x >> y;
        e[a][b] = e[b][a] = min(e[a][b], x);
        c[a][b] = c[b][a] = min(c[a][b], y);
    }
    dijkstra();
    vector<int> path;
    for (int i = ed; i != st;i=pre[i])
        path.push_back(i);
    cout << st;
    for (int i = path.size() - 1; i >= 0;i--)
        cout << ' ' << path[i];
    cout << " " << dis[ed] << " " << cost[ed];

    return 0;
}