#include <bits/stdc++.h>
using namespace std;

int k;
string s;
unordered_set<char> ans;
int main()
{
    cin >> k;
    cin >> s;
    for (int i = 0; i < s.length();i++){
        int j = i + 1;
        while(j<s.length()&&s[j]==s[i])
            j++;
        if((j-i)%k==0)//可能是坏的
            i = j-1;
        else//绝对是好的
            ans.insert(s[i]);
    }
    string res;//记录坏键
    for (int i = 0; i < s.length(); i++)
    {
        if(!ans.count(s[i])&&res.find(s[i])==-1)
            res += s[i];
    }
    cout << res << endl;
    for (int i = 0; i < s.length();i++){//输出一遍
        cout << s[i];
        if(!ans.count(s[i]))
            i += k - 1;
    }
    return 0;
}