#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int cnt[N];
int n, k, top_k[11];
int main()
{
    scanf("%d %d", &n, &k);
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (i > 0)
        {
            printf("%d:", x);
            for (int j = 0; j < num; j++)
                printf(" %d", top_k[j]);
            puts("");
        }
        cnt[x]++;
        bool exist = false;
        for (int j = 0; j < num; j++)
        {
            if (top_k[j] == x)
            {
                exist = 1;
                break;
            }
        }
        if (!exist)
            top_k[num++] = x;
        sort(top_k, top_k + num, [](int p, int q)
            {
                if (cnt[p] != cnt[q])
                    return cnt[p] > cnt[q];
                return p < q;
            });
        num = min(num, k);//保留前k大的数
    }
    return 0;
}