#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> cnt;
int main()
{
    int m, n;
    cin >> m >> n;
    int half = m * n / 2;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
        {
            int t;
            scanf("%d", &t);
            cnt[t]++;
            if(cnt[t]>half)
            {
                printf("%d\n", t);
                return 0;
            }
        }
    return 0;
}