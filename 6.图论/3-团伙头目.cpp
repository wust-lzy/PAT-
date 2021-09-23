#include <bits/stdc++.h>
using namespace std;

int n, k;
unordered_map<string, vector<pair<string, int>>> g;//存储边
unordered_map<string, int> total;
unordered_map<string, bool> vis;

int dfs(string &cur, vector<string> &nodes)
{
    vis[cur] = true;
    nodes.push_back(cur);

    int sum = 0;
    for (auto edge : g[cur])
    {
        sum += edge.second;
        string cur = edge.first;
        if (!vis[cur]) sum += dfs(cur, nodes);
    }
    return sum;
}

int main()
{
    cin >> n >> k;
    while (n -- )
    {
        string a, b;
        int t;
        cin >> a >> b >> t;
        g[a].push_back({b, t});//a跟b打电话
        g[b].push_back({a, t});//b也跟a打电话
        total[a] += t;
        total[b] += t;
    }

    vector<pair<string, int>> res;
    for (auto item : total)
    {
        string cur = item.first;//当前人
        vector<string> nodes;//一个帮派
        int sum = dfs(cur, nodes) / 2;//连通块的权值之和

        if (nodes.size() > 2 && sum > k)//遍历帮派，找到boss
        {
            string boss = nodes[0];
            for (string node : nodes)
                if (total[boss] < total[node])
                    boss = node;
            res.push_back({boss, (int)nodes.size()});
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto item : res) cout << item.first << ' ' << item.second << endl;

    return 0;
}
