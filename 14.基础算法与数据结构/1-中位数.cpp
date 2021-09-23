#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int a[N], b[N], c[N*2];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m;i++)
        scanf("%d", &b[i]);
    int i = 0, j = 0, cnt = 0;
    while(i<n&&j<m){
        if(a[i]<=b[j])
            c[cnt++] = a[i++];
        else
            c[cnt++] = b[j++];
    }
    while(i<n)
        c[cnt++] = a[i++];
    while(j<m)
        c[cnt++] = b[j++];
    printf("%d\n", c[(cnt - 1) / 2]);
    return 0;
}