#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>  pii;
int n,m;
int main()
{
    cin >> n >> m;
    bool vis[n];
    vector<pii> all(m);
    for (int i = 0; i < m; i++)
        scanf("%d %d", &all[i].first, &all[i].second);
    int k;
    cin >> k;
    while(k--)//判断一个点的集合里面 是否每一条边都至少有一个端点在集合内
    {
        memset(vis, 0, sizeof vis);
        int t, p;
        scanf("%d", &t);
        while(t--){
            scanf("%d", &p);
            vis[p] = 1;
        }
        bool flag = 1;
        for (int i = 0; i < m; i++)
        {
            if(!vis[all[i].first]&&!vis[all[i].second])
            {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}