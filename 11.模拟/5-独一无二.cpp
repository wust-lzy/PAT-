#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int vis[N], a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
        vis[a[i]]++;
    }
    for (int i = 0; i < n;i++)
    {
        if(vis[a[i]]==1)
        {
            printf("%d", a[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}