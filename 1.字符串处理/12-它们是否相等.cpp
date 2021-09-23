#include <bits/stdc++.h>
using namespace std;


string change(string s,int n)
{
    int k = s.find(".");//找到小数点
    if(k == -1){
        s += "."; //补点
        k = s.find(".");
    }
    string ans = s.substr(0, k) + s.substr(k + 1);
    while(ans.size() && ans[0]=='0'){//去除前导0
        ans.erase(ans.begin());
        k--;
    }
    if(ans.empty())
        k = 0;
    if(ans.size()>=n)
        ans = ans.substr(0, n);
    else
        ans += string(n - ans.size(), '0');
    return "0." + ans + "*10^" + to_string(k);
}
int main()
{
    int n;
    string a, b;
    cin >>n>> a >> b;
    a = change(a, n);
    b = change(b, n);
    if(a==b)
        cout << "YES " << a;
    else
        cout << "NO " << a << " " << b;
    return 0;
}