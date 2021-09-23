#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e5+10;
int p[N], t[N];//统计字母'P'和'T'的前缀和
char s[N];

int main()
{
    int mod = 1e9 + 7;
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n;i++){//求前缀和
        p[i] = p[i - 1];
        t[i] = t[i - 1];
        if(s[i-1]=='P')
            p[i]++;
        if(s[i-1]=='T')
            t[i]++;
    }
    int ans = 0;
    for (int i = 2; i < n;i++){//遇到'A' a左边的P * a右边的T
        if(s[i-1]=='A'){
            ans += p[i] * (t[n] - t[i]);
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}