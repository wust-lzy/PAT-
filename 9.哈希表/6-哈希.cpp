#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 10010;

int s,n;
int h[N];
int find(int x)//平方探测法
{
    int idx = x % s;
    for (int k = 0; k < s;k++){
        int i = (idx + k * k) % s;
        if(!h[i])
            return i;
    }
    return -1;
}
bool isprime(int x){
    if(x<2)
        return 0;
    for (int i = 2; i <= x / i;i++)
    if(x%i==0)
        return 0;
    return 1;
}
int main()
{
    cin >> s >> n;
    while(!isprime(s))
        s++;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        int idx = find(x);
        if(idx!=-1)
        {
            cout << idx;
            h[idx]=x;
        }
        else
            cout << '-';
            
        if(i!=n-1)
            cout << " ";
    }
        return 0;
}