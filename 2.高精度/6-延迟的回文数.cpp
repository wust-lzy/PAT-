#include <bits/stdc++.h>
using namespace std;

bool check(string &s){
    int n = s.length();
    for (int i = 0; i < n / 2;i++)
    if(s[i]!=s[n-1-i])
        return 0;
    return 1;
}

string add(string &a,string &b){
    int i = a.length() - 1, j = b.length() - 1, add = 0;
    string ans;
    while(i>=0||j>=0||add!=0){
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        add += x + y;
        ans += '0' + add % 10;
        add /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string a;
    cin >> a;
    for (int i = 1; i <= 10;i++){
        if(check(a)){
            printf("%s is a palindromic number.", a.c_str());
            return 0;
        }
        string b(a.rbegin(), a.rend());
        printf("%s + %s = %s\n", a.c_str(), b.c_str(), add(a, b).c_str());
        a = add(a, b);
    }
    puts("Not found in 10 iterations.");
    return 0;
}