#include <bits/stdc++.h>
using namespace std;

int n, d;

bool isprime(int x)
{
    if(x<=1)
        return 0;
    for (int i = 2; i <= x / i;i++)
        if(x%i==0)
            return 0;
    return 1;
}
bool check(int x,int d)  
{
    string s = "";
    while(x)//10进制数转为d进制
    {
        s = s+ (char)(x % d + '0');
        x /= d;
    }
    int ans = 0;
    for(char&c:s)//回文之后转为10进制
        ans = ans * d + c - '0';
    return isprime(ans);//判定是否是质数
}
int main()
{
    while(cin>>n)
    {
        if(n<0)
            break;
        cin >> d;
        if(!isprime(n)){
            puts("No");
            continue;
        }
        printf("%s\n", check(n,d) ? "Yes" : "No");
    }
    return 0;
}