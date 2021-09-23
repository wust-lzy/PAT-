#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int l[N], r[N], n, root, max_idx,ans;
bool hasfather[N];//判断是否有父亲

void dfs(int u,int idx)
{
    if(u==-1)
        return;
    // cout << u << " " << idx << endl;
    if(idx>max_idx){
        max_idx = idx;
        ans = u;
    }
    dfs(l[u],2*idx+1);
    dfs(r[u], 2 * idx + 2);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++){
        string a, b;
        cin >> a >> b;
        if(a=="-")
            l[i] = -1;
        else{
            l[i] = stoi(a);
            hasfather[l[i]] = 1;
        }
        if(b=="-")
            r[i] = -1;
        else{
            r[i] = stoi(b);
            hasfather[r[i]] = 1;
        }
    }
    int root;
    for (int i = 0; i < n; i++){
        if(!hasfather[i]){
            root = i;
            break;
        }
    }
    dfs(root, 0);
    if (max_idx == n-1)
        printf("%s %d", "YES", ans);
    else
        printf("%s %d", "NO", root);
        return 0;
}