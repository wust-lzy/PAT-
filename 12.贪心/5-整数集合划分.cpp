#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum = 0,halfsum=0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n/2;i++)
        halfsum += v[i];
    cout << n % 2 << " " << sum - 2*halfsum;
    return 0;
}