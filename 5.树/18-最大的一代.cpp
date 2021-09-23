#include <bits/stdc++.h>
using namespace std;

const int N = 110;

vector<int> all[N];
int n, m, cnt[N], max_level;
void dfs(int id,int depth)//遍历一遍，每一层节点数++
{
    max_level = max(max_level, depth);
    cnt[depth]++;
    if(all[id].empty())
        return;
    for (int i = 0; i < all[id].size();i++)
        dfs(all[id][i], depth + 1);
}
int main()
{
    cin >> n >> m;//求节点数最多的一层
    while(m--){
        int id, k;
        cin >> id >> k;
        while(k--){
            int son;
            cin >> son;
            all[id].push_back(son);
        }
    }
    dfs(1, 1);
    int idx = 1, max_sum = 0;
    for (int i = 1; i <= max_level; i++)
    {
        if(cnt[i]>max_sum){
            idx = i;
            max_sum = cnt[i];
        }
    }
    cout << max_sum << " " << idx;
    return 0;
}