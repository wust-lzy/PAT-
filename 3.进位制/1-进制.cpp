#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get(char c)
{
    if(c<='9')
        return c - '0';
    return c - 'a' + 10;
}

ll to_ten(string n,ll radix)    //radix转为10进制
{
    ll ans = 0;
    for(char&c:n)
    {
        if((double)ans * radix + get(c)>1e16)//防止溢出
            return 1e18;
        ans = ans * radix + get(c);
        
    }
    return ans;
}
int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    int tag, radix;
    cin >> tag >> radix;

    if(tag==2)
        swap(n1, n2);
    ll target = to_ten(n1, radix);

    ll l = 0, r = max(target,36ll);
    for(char &c:n2)
        l=max(l,get(c)+1);//最小进制是在已经出现的字符当中出现的字母 比如出现z 就是36进制

    while(l<r)
    {
        ll mid = l + r >> 1;
        if(to_ten(n2,mid)>=target)
            r = mid;
        else
            l = mid + 1;
    }
    if(to_ten(n2,l)!=target)
        puts("Impossible");
    else
        cout << l << endl;
    return 0;
}