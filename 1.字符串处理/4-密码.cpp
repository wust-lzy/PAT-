#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> pss;
int main()
{
    int n;
    cin >> n;
    vector<pss> ans;
    int cnt = 0;
    for (int i = 0; i < n;i++)
    {
        string t, s;
        cin >> t >> s;
        bool flag = false;
        for (int i = 0; i < s.size();i++){
            if(s[i]=='1')
                s[i] = '@';
            else if(s[i]=='0')
                s[i] = '%';
            else if(s[i]=='l')
                s[i] = 'L';
            else if(s[i]=='O')
                s[i] = 'o';
            else
                continue;
            flag = true;
        }
        if(flag){
            ans.emplace_back(t, s);
            cnt++;
        }
        
    }
    if(!cnt)
    {
        if(n==1)
            puts("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified\n", n);
    }
    else
    {
        printf("%d\n", cnt);
        for (int i = 0; i < cnt;i++)
            cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}