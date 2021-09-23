#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int s[N];
int n, k;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    scanf("%d", &k);
    while(k--){
        int l, r;
        scanf("%d %d",&l,&r);
        if(l>r)
            swap(l, r);
        printf("%d\n", min(s[r - 1] - s[l - 1], s[n] -s[r-1] + s[l - 1]));
    }
    return 0;
}