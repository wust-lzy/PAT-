#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<char> S;
    string ans = "";
    string s1, s2;
    cin >> s1 >> s2;
    for(char&c:s2){
        if(isalpha(c))
            c = toupper(c);
        S.insert(c);
    }
        
    for(char&c:s1){
        if(isalpha(c))
            c = toupper(c);
        if(!S.count(c)){
            S.insert(c);
            ans += c;
        }
    }
    cout << ans;
    return 0;
}