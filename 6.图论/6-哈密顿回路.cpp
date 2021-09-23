#include <bits/stdc++.h>
using namespace std;

const int N = 210;
int n, m, k;
bool e[N][N];
bool vis[2 * N];
bool check(vector<int> &t)//哈密顿回路 经过所有点且经过一次的一条回路
{
    if(t[0]!=t[t.size()-1]||t.size()!=n+1)//起点等于终点，点数n+1
        return false;
    memset(vis, 0, sizeof vis);
    for(int i=0;i<t.size()-1;i++)//每一条路都能走
    {
        vis[t[i]] = 1;
        if(!e[t[i]][t[i+1]])
            return false;
    }
    for (int i = 1; i <= n;i++)//包含所有点
    if(!vis[i])
        return false;
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b; 
        cin>>a>>b;
        e[a][b] = e[b][a] = 1;
    }
    cin >> k;
    while(k--)
    {
        int cnt;
        cin >> cnt;
        vector<int> t(cnt);
        for (int i = 0; i < cnt;i++)
            cin >> t[i];
        printf("%s\n", check(t) ? "YES" : "NO");
    }
    return 0;
}