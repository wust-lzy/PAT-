#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 510;
int n, m, du[N];
bool e[N][N],vis[N];
int dfs(int u)
{
    vis[u] = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
        if(e[u][i]&&!vis[i])
            ans+=dfs(i);
    return ans;
}
int main()
{
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
        du[a]++, du[b]++;
    }
    int cnt = dfs(1);
    cout << du[1];
    for (int i = 2; i <= n;i++)
        cout << " " << du[i];
    cout << endl;
    if(cnt==n){//连通了
        int s = 0;
        for (int i = 1; i <= n;i++)
        if(du[i]%2==1)
            s++;
        if(s==0)//奇数度数为0
            puts("Eulerian");
        else if(s==2)//奇数度数为2
            puts("Semi-Eulerian");
        else
            puts("Non-Eulerian");
    }else
        puts("Non-Eulerian");
    return 0;
}