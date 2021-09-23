#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
void out(ll a,ll b)
{
    ll t = gcd(a, b);
    a /= t, b /= t;
    if(b<0)
        a *= -1, b *= -1;
    bool isminus = 0;
    if (a < 0){
        isminus = 1;
        printf("(");
    }
    if(b==1)
        cout << a;
    else{
        if(abs(a)>=b){
            printf("%d ", a / b);
            a = abs(a) % b;
        }
        cout << a << "/" << b;
    }
    if(isminus)
        cout << ")";
}
void add(ll a,ll b,ll c,ll d)
{
    out(a, b);
    printf(" + ");
    out(c, d);
    printf(" = ");
    a = a * d + b * c;
    b = b * d;
    out(a, b);
    puts("");
}
void sub(ll a,ll b,ll c,ll d)
{
    out(a, b);
    printf(" - ");
    out(c, d);
    printf(" = ");
    a = a * d - b * c;
    b = b * d;
    out(a, b);
    puts("");
}
void mul(ll a,ll b,ll c,ll d){
    out(a, b);
    printf(" * ");
    out(c, d);
    printf(" = ");
    a = a * c;
    b = b * d;
    out(a, b);
    puts("");

}
void div(ll a,ll b,ll c,ll d)
{
    out(a, b);
    printf(" / ");
    out(c, d);
    printf(" = ");
    if(c==0)
        puts("Inf");
    else{
        a = a * d;
        b = b * c;
        out(a, b);
        puts("");
    }
}
int main()
{
    ll a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    add(a, b, c, d);
    sub(a, b, c, d);
    mul(a, b, c, d);
    div(a, b, c, d);
    return 0;
}