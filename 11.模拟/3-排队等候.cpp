#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, m, k, Q;
int sum[N];
queue<int> q[N];//存储每个窗口完成的时间

int main()
{
    cin >> n >> m >> k >> Q;

    unordered_map<int, int> hash;
    for (int i = 1; i <= k; i ++ )
    {
        int s;
        cin >> s;

        int t = 0;
        for (int j = 0; j < n; j ++ )
            if (i <= n * m)
            {
                if (q[j].size() < q[t].size()) t = j;//在窗口人最少的窗口排队
            }
            else
            {
                if (q[j].front() < q[t].front()) t = j;//最早出队的窗口出队
            }

        sum[t] += s;
        if (i > n * m) q[t].pop();
        q[t].push(sum[t]);

        if (sum[t] - s < 540) hash[i] = sum[t];
    }

    while (Q -- )
    {
        int id;
        cin >> id;
        if (hash.count(id)) printf("%02d:%02d\n", hash[id] / 60 + 8, hash[id] % 60);
        else puts("Sorry");
    }

    return 0;
}