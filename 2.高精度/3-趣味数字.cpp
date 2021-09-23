#include <bits/stdc++.h>
using namespace std;

int cnt1[10], cnt2[10];
vector<int> add(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < n||i<m;i++){
        if(i<n)
            t += a[i];
        if(i<m)
            t += b[i];
        ans.push_back(t % 10);
        t /= 10;
    }
    if(t)
        ans.push_back(t);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        a[i] = s[n - i - 1] - '0';
    vector<int> temp(a);
    vector<int> ans = add(a, temp);//高精度加法
    for(int e:a)
        cnt1[e]++;
    for(int e:ans)
        cnt2[e]++;
    bool flag = true;
    for (int i = 0; i < 10; i++)//统计数字出现的次数
    if(cnt1[i]!=cnt2[i])
    {
        flag = false;
        break;
    }
    printf("%s\n", flag ? "Yes" : "No");
    for (int i = 0; i < ans.size();i++)
        cout << ans[i];
    return 0;
}