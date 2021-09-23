#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 100010;
int a[N], l[N], r[N], ans[N], idx;//a1~ai的最大值，ai~an的最小值

void output()
{
    printf("%d\n",idx);
    for (int i = 0; i < idx;i++){
        printf("%d", ans[i]);
        if(i!=idx-1)
            printf(" ");
    }
    puts("");
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)//a1~ai的最大值
    {
        scanf("%d", &a[i]);
        l[i] = max(l[i - 1], a[i]);
    }
    r[n + 1] = 2e9;
    for (int i = n; i;i--)//ai~an的最小值
        r[i] = min(r[i + 1], a[i]);
    for (int i = 1; i <= n;i++){//满足条件，则可以作为划分
        if(a[i]>l[i-1]&&a[i]<r[i+1])
            ans[idx++] = a[i];
    }
    output();
    return 0;
}