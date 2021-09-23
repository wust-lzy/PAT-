#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1010, M = 1e5 + 10;
int n, l, k;
int head[N], e[M], ne[M], idx;
bool vis[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = head[a], head[a] = idx++;
}
int bfs(int st)
{
    queue<pii> q;
    memset(vis, 0, sizeof vis);
    q.push(pii(st,0));
    vis[st] = 1;
    int cnt = 0;
    while(!q.empty()){
        pii t = q.front();
        q.pop();
        for (int j = head[t.first]; j != -1;j=ne[j]){
            int temp = e[j];
            if(!vis[temp]&&t.second+1<=l){
                vis[temp] = 1;
                cnt++;
                q.push(pii(temp, t.second + 1));
            }
                
        }
    }
    return cnt;
}
int main()
{
    memset(head, -1, sizeof head);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        while (k--)
        { //i关注x
            int x;
            scanf("%d", &x);
            add(x, i);
        }
    }
    scanf("%d", &k);
    while (k--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", bfs(x));
    }
    return 0;
}