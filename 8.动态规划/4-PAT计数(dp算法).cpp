#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e5 + 10;
char s[N], p[] = " PAT";
int f[N][4];    //只考虑前i个字母，且走到了状态j的所有路线的数量
const int mod = 1e9 + 7;
int main()
{
    cin >> s + 1;
    int n = strlen(s + 1);
    f[0][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= 3;j++){
            f[i][j] = f[i - 1][j];//选择不走，跳过这个状态
            if(j<=3&&s[i]==p[j])//当前s[i]可以走到下一个状态
                f[i][j] = (f[i - 1][j - 1] + f[i][j]) % mod;
        }
    }
    cout << f[n][3];
    return 0;
}