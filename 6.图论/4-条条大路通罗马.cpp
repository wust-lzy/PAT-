#include <bits/stdc++.h>
using namespace std;

const int N = 210, inf = 1e8;

int n, m;
string city[N];
int cnt[N],sum[N],cost[N],dis[N], pre[N];//最短路数量，最小点数，最大幸福
int w[N],e[N][N];//点权，边权
unordered_map<string, int> mp;//单词映射成数字
bool vis[N];
void dijkstra()//dijkstra
{//距离最短->最大幸福感的路线->平均幸福感最大的路线，数据保证这种路线唯一。
    fill(dis, dis + N, inf);
    dis[1] = 0, cnt[1] = 1;
    for (int i = 0; i < n;i++)
    {
        int u = -1;
        for (int j = 1; j <= n;j++){
            if(!vis[j]&&(u==-1||dis[u]>dis[j]))
                u = j;
        }
        vis[u] = 1;
        for (int v = 1; v <= n;v++){
            if(dis[v]>dis[u]+e[u][v])
            {
                dis[v] = dis[u] + e[u][v];
                cnt[v] = cnt[u];
                cost[v] = cost[u] + w[v];
                sum[v] = sum[u] + 1;
                pre[v] = u;
            }else if(dis[v]==dis[u]+e[u][v]){
                cnt[v] += cnt[u];
                if(cost[v]<cost[u]+w[v]){
                    cost[v] = cost[u] + w[v];
                    sum[v] = sum[u] + 1;
                    pre[v] = u;
                }
                else if(cost[v]==cost[u]+w[v]){
                    if(sum[v]>sum[u]+1){
                        sum[v] = sum[u] + 1;
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
int main()
{
    fill(e[0], e[0] + N * N, inf);
    cin >> n >> m >> city[1];
    mp[city[1]] = 1;
    for (int i = 2; i <= n;i++){//单词映射成数字
        int x;
        cin >> city[i] >> x;
        mp[city[i]] = i;
        w[i] = x;
    }
    while(m--){//构造边
        string a, b;
        int x;
        cin >> a >> b >> x;
        e[mp[a]][mp[b]] = e[mp[b]][mp[a]] = min(e[mp[a]][mp[b]],x);
    }
    dijkstra();
    int ed = mp["ROM"];//输出最短路数量，最短路距离，最大幸福感，平均幸福感
    cout << cnt[ed] << " " << dis[ed] << " " << cost[ed] << " " << cost[ed] / sum[ed] << endl;
    vector<int> path;
    for (int i = ed; i != 1;i=pre[i])
        path.push_back(i);
    cout << city[1];
    for (int i = path.size() - 1; i >= 0;i--)
        cout << "->" << city[path[i]];
    return 0;
}