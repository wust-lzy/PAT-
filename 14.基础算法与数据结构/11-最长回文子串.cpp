#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
bool f[N][N];
int ans;
string s;
int main()
{
    getline(cin, s);
    int n = s.length();
    for (int l = 1; l <= n;l++){
        for (int i = 0; i + l - 1 < n; i++)
        {
            int j = i + l-1;
            if(l==1)
                f[i][j] = 1;
            else if(l==2)
                f[i][j] = s[i] == s[j];
            else
                f[i][j] = f[i + 1][j - 1] && s[i] == s[j];
            if(f[i][j])
                ans = max(ans, l);
        }
    }
    cout << ans;
    return 0;
}