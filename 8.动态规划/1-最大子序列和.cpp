#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e4+10;
int a[N];
int main()
{
    int n;
    cin >> n;
    int ans = -1, l, r;
    for (int i = 0, last = -1, st=0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (last < 0){
            last = 0;
            st = i;
        }
        last += a[i];
        if(last>ans){
            ans = last;
            l = a[st], r = a[i];
        }
    }
    if(ans<0)
        ans = 0, l = a[0], r = a[n - 1];
    printf("%d %d %d", ans, l, r);
    return 0;
}