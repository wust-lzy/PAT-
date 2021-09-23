#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 10010;

int s, n, q;
int h[N];
int find(int x,int &cnt) //平方探测法
{
    cnt = 1;
    for (int k = 0; k < s; k++,cnt++)
    {
        int idx = (x%s + k * k) % s;
        if (!h[idx]||h[idx]==x)
            return idx;
    }
    return -1;
}
bool isprime(int x)
{
    if (x < 2)
        return 0;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int main()
{
    cin >> s >> n >> q;
    while (!isprime(s))
        s++;
    for (int i = 0; i < n; i++)
    {
        int x, cnt;
        cin >> x;
        int idx = find(x,cnt);
        if (idx == -1)
            printf("%d cannot be inserted.\n", x);
        else
            h[idx]=x;
    }
    int sum = 0;
    for (int i = 0; i < q; i++)
    {
        int x, cnt;
        cin >> x;
        find(x, cnt);
        sum += cnt;
    }
    printf("%.1lf\n", (double)sum/ q);
    return 0;
}