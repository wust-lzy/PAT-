#include <bits/stdc++.h>
using namespace std;
string s1,s2;
unordered_map<char, int> cnt;

int main()
{
    cin >> s1 >> s2;
    for(char&c:s1)
        cnt[c]++;
    bool ok = 1;
    int ans = 0;
    for (char &c : s2){
        if(cnt[c]==0){
            ok = 0;
            ans++;
        }
        else
            cnt[c]--;
    }
    if(ok)
        cout << "Yes " << s1.length() - s2.length();
    else
        cout << "No " << ans;

    return 0;
}