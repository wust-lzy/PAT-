#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 210, M = 1e4 + 10;
int a[N],b[M];
int n, m;
int longestCommonSubsequence()
{
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])//一个可以对应多个
                f[i][j] = f[i][j - 1] + 1;
            else
                f[i][j]=max(f[i - 1][j], f[i][j - 1]);
        }
    }
    return f[n][m];
}
int main()
{
    cin >> n >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    cin >>m;
    for (int i = 1; i <= m;i++)
        cin >> b[i];
    cout << longestCommonSubsequence();
    return 0;
}
