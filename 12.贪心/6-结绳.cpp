#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 1; i < n;i++)
        a[i] = (a[i] + a[i - 1]) / 2;
    cout << a[n - 1];
    return 0;
}