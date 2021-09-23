#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1010;
int n;
int l[N], r[N], v[N], idx;//结点左孩子编号，右孩子编号，每个编号对应的值，下标
int cnt[N], root, max_depth;

void ins(int &u,int data)//结点编号，数据
{
    if(!u){//当前编号结点没有初始化
        u = ++idx;
        v[u] = data;
    }
    else if(data<=v[u])
        ins(l[u], data);
    else
        ins(r[u], data);
}
void dfs(int u,int depth)
{
    if(!u)
        return;
    cnt[depth]++;//每层数量++
    max_depth = max(max_depth, depth);
    dfs(l[u], depth + 1);
    dfs(r[u], depth + 1);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        ins(root, x);
    }
    dfs(root, 0);//遍历一遍
    int n1 = cnt[max_depth], n2 = cnt[max_depth - 1];
    printf("%d + %d = %d", n1, n2, n1 + n2);
    return 0;
}