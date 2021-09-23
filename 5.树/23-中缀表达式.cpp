#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 30;
int n;
int l[N], r[N];
string val[N];
bool father[N], leaf[N];
int root;
string dfs(int u)//递归求表达式，不为根，且不为叶子结点，就加括号
{
    string left, right;
    if(l[u]!=-1){
        left = dfs(l[u]);
        if(l[u]!=root&&!leaf[l[u]])
            left = "(" + left + ")";
    }
    if(r[u]!=-1){
        right = dfs(r[u]);
        if(r[u]!=root&&!leaf[r[u]])
            right = "(" + right + ")";
    }
    return left + val[u] + right;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> val[i] >> l[i] >> r[i];//标记每个结点的值，左右儿子
        if(l[i]!=-1)//左右儿子不为空 则标记左右儿子的父亲
            father[l[i]] = 1;
        if(r[i]!=-1)
            father[r[i]] = 1;
        if(l[i]==-1&&r[i]==-1)
            leaf[i] = 1;
    }
    for (int i = 1; i <= n;i++)
    if(!father[i]){//没有父亲，为根结点
        root = i;
        break;
    }
    cout << dfs(root);
    return 0;
}