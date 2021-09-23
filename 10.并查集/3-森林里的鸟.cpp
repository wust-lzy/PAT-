#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 10010;
int n, q, k, cnt;
int father[N];

int findfather(int x)
{
    if (father[x] == x)
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}

void Union(int a, int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if (fa != fb)
        father[fa] = fb;
}
int main()
{
    FAST;
    unordered_set<int> birds;
    for (int i = 1; i < N; i++)
        father[i] = i;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int fir, x;
        cin >> k >> fir;
        birds.insert(fir);
        for (int j = 1; j < k; j++)
        {
            cin >> x;
            birds.insert(x);
            Union(x,fir);
        }
    }
    for(int e:birds)
        if(e==findfather(e))
            cnt++;
    cout << cnt << " " << birds.size() << endl;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        printf("%s\n", findfather(a) == findfather(b) ? "Yes" : "No");
    }

    return 0;
}