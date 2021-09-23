#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 50010;
int in[N], pre[N];
int n;
bool flag = false;
unordered_map<int, int> pos;//记录每个值在中序遍历中的位置
void build(int root,int st,int ed)
{
    if(st>ed||flag)
        return;
    int i = pos[pre[root]];
    build(root + 1, st, i - 1);//递归遍历左子树
    build(root + (i - st) + 1, i + 1, ed);//右子树
    if(!flag){
        flag = 1;
        cout << pre[root];
    }
}
int main()
{
    FAST;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n;i++){
        cin >> in[i];
        pos[in[i]] = i;
    }
    build(0, 0, n - 1);
    return 0;
}