#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

int main()
{
    ll a = 0, b = 1;//分数乘法 a/b+c/d = (a*d+b*c)/(b*d)
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        ll c, d;
        scanf("%lld/%lld", &c, &d);//约分 c/d
        ll t = gcd(c, d);
        d /= t, c /= t;

        t = gcd(b, d);//防止溢出求b跟d的最大公约数
        a = a * (d/t) + b/t * c;//更新a，b
        b = b/t * d;
        t = gcd(a, b);
        a /= t, b /= t;
    }
    if(b==1)
        cout << a;
    else{
        if(a>=b){
            cout << a / b<<" ";
            a %= b;
        }
        printf("%lld/%lld", a, b);
    }
    return 0;
}