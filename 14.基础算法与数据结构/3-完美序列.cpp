#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 100010;
int a[N];
int n, p;
int main()
{
    FAST;
    int ans = 0;
    cin >> n >> p;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0, j = 0; j < n;j++){//滑动窗口
        while((ll)a[i]*p<a[j])
            i++;
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return 0;
}