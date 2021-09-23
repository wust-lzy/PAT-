#include <bits/stdc++.h>
using namespace std;

const int N = 510, inf = 1e8;

int n,m,st,ed;
int w[N];
int e[N][N], dis[N], cnt[N], sum[N];

bool vis[N];
void dijkstra()//dijkstra
{
    fill(dis, dis + N, inf);
    dis[st] = 0, cnt[st] = 1, sum[st] = w[st];
    for (int i = 0; i < n;i++){
        int u = -1;
        for (int j = 0; j < n;j++){
            if(!vis[j]&&(u==-1||dis[u]>dis[j]))
                u = j;
        }
        if(u==-1)
            break;
        vis[u] = 1;
        for (int v = 0; v < n;v++){
            if(dis[v]>dis[u]+e[u][v]){
                dis[v] = dis[u] + e[u][v];
                cnt[v] = cnt[u];
                sum[v] = sum[u] + w[v];
            }else if(dis[v]==dis[u]+e[u][v]){
                cnt[v] += cnt[u];
                sum[v] = max(sum[v], sum[u] + w[v]);
            }
        }
    }
}
int main()
{
    cin >> n >> m >> st >> ed;
    for (int i = 0; i < n;i++)
        cin >> w[i];
    fill(e[0], e[0] + N * N, inf);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = min(e[a][b], c);
    }
    dijkstra();
    cout << cnt[ed] << " " << sum[ed] << endl;
    return 0;
}