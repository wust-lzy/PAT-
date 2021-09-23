#include <iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<vector>
using namespace std;

const int N = 100010;

int main()
{
    unordered_map<string, int> cnt;
    string s;
    getline(cin, s);
    int i = 0;
    int n = s.length();
    while (i < n)
    {
        if(isalnum(s[i]))//遇到一个单词
        {
            int j = i;
            while(j<n&&isalnum(s[j])){
                s[j] = tolower(s[j]);
                j++;
            }
            cnt[s.substr(i, j - i)]++;  //存入一个单词
            i = j;
        }
        else
            i++;
    }
    int maxn = 0;
    vector<string> ans;
    for(auto&c:cnt){
        if(c.second>maxn){
            maxn = c.second;
            ans.clear();
            ans.push_back(c.first);
        }
        else if(c.second==maxn)
            ans.push_back(c.first);
    }
    sort(ans.begin(), ans.end());//取字典序最小
    cout << ans[0] << " " << maxn;
    return 0;
}