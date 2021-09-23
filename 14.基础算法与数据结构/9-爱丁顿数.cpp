#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e5+10;
int a[N];

int main()
{
    FAST;
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = n; i>=1;i--){
        if(a[n-i+1]>i)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    cout << 0;
    return 0;
}