#include <bits/stdc++.h>
using namespace std;

const int N = 210;
bool e[N][N];
int n, m;

bool check(vector<int>&p)//判断每两个点都是都是一条边
{
    int t = p.size();
    for (int i = 0; i < t; i++){
        for (int j = i + 1; j < t; j++)
        {
            if (!e[p[i]][p[j]])
                return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> n >> m;
    bool vis[n+1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
    }
    int k;
    cin >> k;
    while(k--)
    {
        memset(vis, 0, sizeof vis);
        int t;
        cin >> t;
        vector<int> p(t);
        for (int i = 0; i < t;i++)
        {
            cin >> p[i];
            vis[p[i]] = 1;
        }
        bool ans = check(p);
        if(ans){
            bool flag = 1;
            for (int i = 1; i <= n;i++)//判断是否是最大团
            {
                if(!vis[i]){
                    p.push_back(i);
                    if(check(p)){
                        flag = 0;
                        break;
                    }
                    p.pop_back();
                }
            }
            printf("%s\n", flag ? "Yes" : "Not Maximal");
        }
        else
            puts("Not a Clique");
    }
    return 0;
}