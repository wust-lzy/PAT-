#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 110;

int n, m, S;
int w[N];
bool g[N][N];

vector<vector<int>> ans;

void dfs(int u,int sum,vector<int>&path)////搜索所有到叶子结点权值之和为S的路径
{
    bool leaf = 1;
    for (int i = 0; i < n; i++){
        if(g[u][i]){
            leaf = 0;
            break;
        }
    }
    
    if(leaf){
        if(sum==S)
            ans.push_back(path);
    }
    else{
        for (int i = 0; i < n;i++){
            if(g[u][i]){
                path.push_back(w[i]);
                dfs(i, sum + w[i], path);
                path.pop_back();
            }
        }
    }
}
int main()
{
    cin >> n >> m >> S;//点数，边数，权值总和
    for (int i = 0; i < n;i++)
        cin >> w[i];
    while(m--){
        int id, k;
        cin >> id >> k;
        while(k--){
            int son;
            cin >> son;
            g[id][son] = 1;
        }
    }
    vector<int> path({w[0]});
    dfs(0, w[0], path);
    // cout<<ans.size();
    sort(ans.begin(), ans.end(),greater<vector<int>>());
    for(auto&v:ans){
        bool fir=1;
        for(auto&e:v){
            if(fir){
                fir=0;
                cout<<e;
            }else   cout<<" "<<e;
        }
        puts("");
    }
    return 0;
}