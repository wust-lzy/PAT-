#include <bits/stdc++.h>
using namespace std;

int n, b;

vector<int> ans;
void output(vector<int> &p)
{
    for (int i = 0; i < p.size();i++){
        printf("%d", p[i]);
        if(i!=p.size()-1)
            printf(" ");
    }
}
bool Palindromic(){
    for (int i = 0; i < ans.size() / 2;i++){
        if(ans[i]!=ans[i-1])
            return 0;
    }
    return 1;
}
int main()
{
    cin >> n >> b;
    while(n){
        ans.push_back(n % b);
        n /= b;
    }
    printf("%s\n", Palindromic() ? "Yes" : "No");
    reverse(ans.begin(), ans.end());
    output(ans);
    return 0;
}