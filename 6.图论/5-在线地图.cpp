#include <bits/stdc++.h>
using namespace std;

const int N = 510, inf = 1e8;
int n, m,st,ed;
int dis[N], cost[N], sum[N];
int pre1[N], pre2[N], e[N][N], ti[N][N];
bool vis[N];
void dijstra1()//求最短，相同距离求最快
{
    fill(dis, dis + N, inf);
    fill(cost, cost + N, inf);
    dis[st] = 0, cost[st] = 0;
    for (int i = 0; i < n;i++){
        int u = -1;
        for (int j = 0; j < n;j++){
            if(!vis[j]&&(u==-1||dis[u]>dis[j]))
                u = j;
        }
        vis[u] = 1;
        for (int v = 0; v < n;v++){
            if(dis[v]>dis[u]+e[u][v]){
                dis[v] = dis[u] + e[u][v];
                cost[v] = cost[u] + ti[u][v];
                pre1[v] = u;
            }
            else if(dis[v]==dis[u]+e[u][v]){
                if(cost[v]>cost[u]+ti[u][v]){
                    cost[v] = cost[u] + ti[u][v];
                    pre1[v] = u;
                }
            }
        }
    }
}

void dijstra2()//最快的，如果有多条，选择经过点最少的
{
    fill(cost, cost + N, inf);
    memset(vis, 0, sizeof vis);
    cost[st] = 0;
    for (int i = 0; i < n;i++){
        int u = -1;
        for (int j = 0; j < n;j++){
            if(!vis[j]&&(u==-1||cost[u]>cost[j]))
                u = j;
        }
        vis[u] = 1;
        for (int v = 0; v < n;v++){
            if(cost[v]>cost[u]+ti[u][v]){
                cost[v] = cost[u] + ti[u][v];
                sum[v] = sum[u] + 1;
                pre2[v] = u;
            }
            else if(cost[v]==cost[u]+ti[u][v]&&sum[v]>sum[u]+1){
                sum[v] = sum[u] + 1;
                pre2[v] = u;
            }
        }
    }
}
int main()
{
    fill(e[0], e[0] + N * N, inf);
    fill(ti[0], ti[0] + N * N, inf);
    cin >> n >> m;
    int a, b, flag, len, t;
    while(m--){
        cin >> a >> b >> flag >> len >> t;
        e[a][b] = min(e[a][b],len);
        ti[a][b] = min(ti[a][b],t);
        if(!flag){
            e[b][a] = min(e[b][a], len);
            ti[b][a] = min(ti[b][a], t);
        }
    }
    cin >> st >> ed;
    vector<int> path1, path2;
    dijstra1();
    dijstra2();
    for (int i = ed; i != st;i=pre1[i])//保存路径
        path1.push_back(i);
    for (int i = ed; i != st;i=pre2[i])
        path2.push_back(i);
    if(path1==path2){//特判路径相同输出
        printf("Distance = %d; Time = %d: %d", dis[ed], cost[ed], st);
        for (int i = path1.size() - 1; i >= 0;i--)
            printf(" -> %d", path1[i]);
        cout << endl;
    }
    else{
        printf("Distance = %d: %d", dis[ed], st);
        for (int i = path1.size() - 1; i >= 0;i--)
            printf(" -> %d", path1[i]);
        cout << endl;
        printf("Time = %d: %d", cost[ed], st);
        for (int i = path2.size() - 1; i >= 0;i--)
            printf(" -> %d", path2[i]);
    }
    return 0;
}