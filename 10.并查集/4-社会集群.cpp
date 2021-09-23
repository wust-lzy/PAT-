#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int father[N], isroot[N];
int vis[N];
int n, k;
int findfather(int x)
{
    if(x==father[x])
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}
void Union(int a,int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb)
        father[fa] = fb;
}
int main()
{
    
    cin >> n;
    for (int i = 1; i <= n;i++)
        father[i] = i;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d:", &k);
        for (int j = 0; j < k;j++)
        {
            int x;
            scanf("%d", &x);//每个爱好
            if(!vis[x])//将每个爱好绑定到每个人
                vis[x] = i;
            Union(i, vis[x]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n;i++)
        isroot[findfather(i)]++;
    for (int i = 1; i <= n;i++)
    if(isroot[i])
        cnt++;
    cout << cnt << endl;
    sort(isroot + 1, isroot + 1 + n, [](int &a, int &b)
         { return a > b; });
    for (int i = 1; i <= cnt;i++)
    {
        cout << isroot[i];
        if(i!=cnt)
            cout << " ";
    }
    return 0;
}
