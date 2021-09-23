#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1010;
int n, heap[N];
bool gt,lt;//堆的特征，单调递增或者递减
vector<int> path;

void dfs(int u)
{
    path.push_back(heap[u]);
    if(u*2>n){//叶子结点
        cout << path[0];
        for (int i = 1; i < path.size();i++){
            cout << " " << path[i];
            if(path[i]>path[i-1])
                lt = 1;
            else
                gt = 1;
        }
        cout << endl;
        path.pop_back();
        return;
    }
    if(u*2+1<=n)//遍历右子树
        dfs(u * 2 + 1);
    if(u*2<=n)  //遍历左子树
        dfs(u * 2);
    path.pop_back();
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> heap[i];
    dfs(1);
    if (gt && lt)
        puts("Not Heap");
    else if(lt)
        puts("Min Heap");
    else
        puts("Max Heap");
    return 0;
}