#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 55;
unordered_set<int> S[N];
int main()
{
    FAST;
    int n, k, t;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        while(k--)
        {
            cin >> t;
            S[i].insert(t);
        }
    }
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        int nc = 0, nt = 0; //交集，并集
        for (const int &e : S[x])
        {
            if (S[y].count(e))
                nc++;
        }
        nt = S[x].size() + S[y].size() - nc; //求并集
        // cout<<nc<<" "<<nt<<endl;
        printf("%.1lf%%\n", nc * 100.0 / nt);
    }
    return 0;
}