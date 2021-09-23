#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
bool vis[N];
bool isprime(int n)
{
    if(n<2)
        return 0;
    for (int i = 2; i<=n/i; i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int n,k;
    cin >> n;
    int q[n];
    unordered_map<int, int> rank;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        rank[t] = i + 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int t;
        scanf("%d", &t);
        if (!rank[t])
            printf("%04d: Are you kidding?\n", t);
        else if(vis[t])
            printf("%04d: Checked\n", t);
        
        else if (rank[t]==1)
            printf("%04d: Mystery Award\n", t);
        else if (isprime(rank[t]))
            printf("%04d: Minion\n", t);
        else
            printf("%04d: Chocolate\n", t);
        vis[t] = 1;
    }
    return 0;
}