#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e5+10;
int amounts[N], n;
int father[N], f[N];//记录每个结点的父亲，每个点是第几层
double ans = 0, p, r;

int dfs(int u)//自底向上搜索
{
    if(f[u]!=-1)
        return f[u];
    // if(father[u]==-1)
    //     return f[u] = 0;
    // return f[u] = dfs(father[u]) + 1;
    if(father[u]==-1)
        f[u] = 0;
    else
        f[u] = dfs(father[u]) + 1;
    return f[u];
}
int main()
{
    FAST;
    cin >> n >> p >> r;
    memset(f, -1, sizeof f);
    memset(father, -1, sizeof father);
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
            father[son] = i;
        }
    }
    for (int i = 0; i < n;i++)
    if(amounts[i])
        ans += amounts[i] * p * pow(1 + r / 100, dfs(i));
    printf("%.1lf", ans);
    return 0;
}