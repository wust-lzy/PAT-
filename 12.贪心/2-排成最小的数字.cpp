#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
string a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n, [](string &s1, string &s2){
        return  s1+s2 < s2 + s1; 
    });
    int idx = 0;
    string ans;
    for (int i = 0; i < n;i++)
        ans += a[i];
    while(ans[idx]=='0')
        idx ++;
    cout << ans.substr(idx);
    return 0;
}