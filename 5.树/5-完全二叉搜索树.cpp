#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1010;
int in[N],ans[N];
int n, cnt = 0;
void dfs(int idx)
{
    if(2*idx+1<n)
        dfs(2 * idx + 1);
    ans[idx] = in[cnt++];
    if(2*idx+2<n)
        dfs(2 * idx + 2);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> in[i];
    sort(in, in + n);
    dfs(0);
    for (int i = 0; i < n;i++){
        cout << ans[i];
        if(i!=n-1)
            cout << " ";
    }
        return 0;
}