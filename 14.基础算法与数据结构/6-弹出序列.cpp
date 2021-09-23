#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1010;
int popv[N];
int n, m, k;

bool check()
{
    stack<int> stk;
    for (int i = 1, j = 1; i <= n;i++){
        stk.push(i);
        if(stk.size()>m)
            return 0;
        while(!stk.empty()&&stk.top()==popv[j]){
            stk.pop();
            j++;
        }
    }
    return stk.empty();
}
int main()
{
    FAST;
    cin >> m >> n >> k;
    while(k--){
        for (int i = 1; i <= n;i++)
            cin >> popv[i];
        printf("%s\n", check() ? "YES" : "NO");
    }
        return 0;
}