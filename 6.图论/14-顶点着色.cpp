#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e4 + 10, M = N;
int n, m, k;
pii e[M];
int color[N];
unordered_set<int> S;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m;i++)
        scanf("%d %d", &e[i].first, &e[i].second);
    scanf("%d", &k);
    while(k--){
        S.clear();
        for (int i = 0; i < n;i++)
        {
            scanf("%d", &color[i]);
            S.insert(color[i]);
        }
        bool flag = 1;
        for (int i = 0; i < m; i++)//每条边的两个点颜色不能相同
        {
            if(color[e[i].first]==color[e[i].second])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("%d-coloring\n", S.size());
        else
            puts("No");
    }
    return 0;
}