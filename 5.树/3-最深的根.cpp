#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 10010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int father[N];

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int findfather(int x)
{
    if (father[x] == x)
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}

void unoin(int a,int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb)
        father[fa] = fb;
}
int dfs(int u,int father) //记录来源点  因为无向图可能重复搜
{
    int depth = 0;
    for (int i = h[u]; ~i;i=ne[i])
    {
        int j = e[i];
        if(j==father)//重复搜索了
            continue;
        depth = max(depth, dfs(j,u) + 1);
    }
    return depth;
}
int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);//初始化邻接表
    for (int i = 1; i <= n;i++)
        father[i] = i;
    int k = n;  //n个连通块
    for (int i = 0; i < n - 1;i++)//并查集求集合个数
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(findfather(a)!=findfather(b))
        {
            k--;//a，b连通到一起 连通块-1
            unoin(a, b);
        }
        add(a, b);
        add(b, a);
    }
    if(k>1){
        printf("Error: %d components", k);
        return 0;
    }
    vector<int> ans;
    int max_depth = -1;
    
    for (int i = 1; i <= n; i++)
    {
        int depth = dfs(i,-1);
        if(depth>max_depth)
        {
            max_depth = depth;
            ans.clear();
            ans.emplace_back(i);
        }
        else if(depth==max_depth)
            ans.emplace_back(i);
    }
    for(int&e:ans)
        printf("%d\n", e);
    return 0;
}