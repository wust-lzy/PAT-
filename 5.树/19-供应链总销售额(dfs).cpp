#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e5+10;
int amounts[N];
int n;
int h[N], e[N], ne[N], idx;
double ans = 0, p, r;
int max_lev;
void add(int a, int b) //插入一条a到b的边
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u,int depth)
{
    if(h[u]==-1)//说明是叶子节点
        ans += p * pow((1.0 + r / 100), depth)*amounts[u];
    for (int i = h[u]; ~i;i=ne[i])
        dfs(e[i], depth + 1);
}
int main()
{
    FAST;
    cin >> n>>p>>r;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n;i++)
    {
        int k;
        cin >> k;
        if(!k)
            cin >> amounts[i];
        while(k--)
        {
            int son;
            cin >> son;
            add(i, son);
        }
    }
    dfs(0, 0);//根结点，层数
    printf("%.1lf", ans);
    return 0;
}