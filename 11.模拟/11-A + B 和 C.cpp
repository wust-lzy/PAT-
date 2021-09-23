#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll a, ll b,ll c){
    ll sum=a+b;
    if(a>=0&&b>=0&&sum<0)
        return true;
    if(a<0&&b<0&&sum>=0)
        return false;
    return a + b > c;
}
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: %s\n", i, check(a, b, c) ? "true" : "false");
    }
    return 0;
}