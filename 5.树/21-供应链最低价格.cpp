#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e5+10;
int n;
int father[N], f[N];//记录每个结点的父亲，每个点是第几层
double  p, r;
bool leaf[N];

int dfs(int u)//自底向上搜索
{
    if(f[u]!=-1)
        return f[u];
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
            leaf[i] = 1;
        while (k--)
        {
            int son;
            cin >> son;
            father[son] = i;
        }
    }
    double minn = 1e7;
    int cnt = 1;
    for (int i = 0; i < n; i++)
        if(leaf[i]){
            double t = p * pow(1 + r/100, dfs(i));
            if(minn>t){
                cnt = 1;
                minn = t;
            }
            else if(minn==t)
                cnt++;
        }
    printf("%.4lf %d", minn,cnt);
    return 0;
}