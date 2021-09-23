#include <bits/stdc++.h>
using namespace std;

const int N=100;
int main()
{
    char t[N];
    char ans1[N], ans2[N];
    int h, m, s;
    int h2, m2, s2;
    int n;
    cin >> n;
    int minn = 1e8, maxn = 0;
    while (n--)
    {
        scanf("%s %d:%d:%d %d:%d:%d", t,&h, &m, &s, &h2, &m2, &s2);
        int t1 = h * 3600 + m * 60 + s;
        int t2 = h2 * 3600 + m2 * 60 + s2;
        if(t1<minn){
            minn = t1;
            strcpy(ans1, t);
        }
        if(t2>maxn){
            maxn = t2;
            strcpy(ans2, t);
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}