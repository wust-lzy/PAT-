#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int n, k, m;
int p[10];
struct node
{
    int id, cnt = 0, total=0;
    int g[6];
    node(){}
    node(int _id)
    {
        id = _id;
        for (int i = 1; i <= k;i++)
            g[i] = -2;
    }
    void cal()
    {
        for (int i = 1; i <= k;i++)
        {
            total += max(0, g[i]);
            if(g[i]==p[i])
                cnt++;
        }    
        
    }
    bool is_submmit()
    {
        for (int i = 1; i <= k;i++)
        if(g[i]>=0)
            return 1;
        return 0;
    }
};

unordered_map<int, node>all;
int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= k;i++)
        cin >> p[i];
    vector<node> ans;
    while(m--)
    {
        int id, idx, x;
        cin >> id >> idx >> x;
        if(!all.count(id))
            all[id] = node(id);
        all[id].g[idx] = max(all[id].g[idx], x);
    }
    for(auto &e:all)
    {
        auto &u = e.second;
        if(u.is_submmit())
        {
            u.cal();
            ans.push_back(u);
        }
    }
    sort(ans.begin(), ans.end(),[](node&u1,node&u2)
    {
        if(u1.total!=u2.total)
            return u1.total > u2.total;
        if(u1.cnt!=u2.cnt)
            return u1.cnt > u2.cnt;
        return u1.id < u2.id;
    });
    int len = ans.size();
    for (int i = 0,rank=1; i < len;i++)
    {
        if(i&&ans[i].total!=ans[i-1].total)
            rank = i + 1;
        printf("%d %05d %d",rank,ans[i].id,ans[i].total);
        for (int j = 1; j <= k;j++)
        if(ans[i].g[j]==-2)
            printf(" -");
        else
            printf(" %d", max(0, ans[i].g[j]));
        puts("");
    }
        return 0;
}