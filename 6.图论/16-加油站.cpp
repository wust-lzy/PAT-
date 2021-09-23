#include <bits/stdc++.h>
using namespace std;

const int N = 1020, inf = 1e7;
int n, m, k, d;
int e[N][N], dis[N];
bool vis[N];

int get(string &s)
{
    if(s[0]=='G')
        return n+stoi(s.substr(1));
    return stoi(s);
}
void dijkstra(int st,int &mind,int &sumd)
{
    fill(dis, dis + N, inf);//求加油站到所有房屋，最近距离的最大值
    memset(vis, 0, sizeof vis);
    dis[st] = 0;
    for (int i = 0; i < n + m;i++){
        int u = -1;
        for (int j = 1; j <= n + m;j++)
        if(!vis[j]&&(u==-1||dis[u]>dis[j]))
            u = j;
        vis[u] = 1;
        for (int v = 1; v <= n + m;v++)
            dis[v] = min(dis[v], dis[u] + e[u][v]);
    }
    for (int i = 1; i <= n;i++)
    {
        if(dis[i]>d)
        {
            mind = -inf;
            return;
        }
    }
    mind = inf, sumd = 0;
    for (int i = 1; i <= n;i++){
        mind = min(mind, dis[i]);
        sumd += dis[i];
    }
}

int main()
{
    fill(e[0], e[0]+ N * N, inf);
    cin >> n >> m >> k >> d;
    while(k--){
        string a, b;
        int c;
        cin >> a >> b >> c;
        int x = get(a), y = get(b);
        e[x][y] = e[y][x] = min(e[x][y], c);
    }
    int ans = -1, mind = 0, sumd = inf;
    for (int i = n + 1; i <= n + m;i++){
        int d1=0, d2=0;
        dijkstra(i, d1, d2);
        if(d1>mind)
        {
            mind = d1;
            ans = i;
            sumd = d2;
        }
        else if(d1==mind&&d2<sumd){//最近距离相同，求最小平均值的一个
            ans = i;
            sumd = d2;
        }
    }
    if(ans==-1)
        puts("No Solution");
    else{
        printf("G%d\n", ans - n);
        printf("%.1lf %.1lf\n", 1.0 * mind, (1.0 * sumd+1e-7) / n);//处理精度问题
    }
    return 0;
}