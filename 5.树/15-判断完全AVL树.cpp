#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 30;

int l[N], r[N], v[N], h[N], idx;
int n, root = 0, pos[N];
void update(int u) //更新高度
{
    h[u] = max(h[l[u]], h[r[u]]) + 1;
}

void R(int &u)
{
    int p = l[u];
    l[u] = r[p], r[p] = u;
    update(u), update(p);
    u = p;
}

void L(int &u)
{
    int p = r[u];
    r[u] = l[p], l[p] = u;
    update(u), update(p);
    u = p;
}

int get_balance(int u)//获取高度差，判断是哪种类型
{
    return h[l[u]] - h[r[u]];
}

void ins(int &u,int data)
{
    if(!u)  //如果root树空的
        u = ++idx, v[u] = data;
    else if(data<v[u])
    {
        ins(l[u], data);
        if(get_balance(u)==2)
        {
            if(get_balance(l[u])==1)
                R(u);
            else{
                L(l[u]);
                R(u);
            }
        }
    }
    else{
        ins(r[u], data);
        if(get_balance(u)==-2)
        {
            if(get_balance(r[u])==-1)
                L(u);
            else{
                R(r[u]);
                L(u);
            }
        }
    }
    update(u);//调整高度
}
void bfs(int root)//层序遍历
{
    queue<int> q;
    q.push(root);
    vector<int> ans;
    pos[root] = 1;
    bool flag = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if(pos[t]>n)
            flag = false;
        ans.push_back(v[t]);
        if (l[t]){
            q.push(l[t]);
            pos[l[t]] = pos[t] * 2;
        }

        if(r[t]){
            pos[r[t]] = pos[t] * 2 + 1;
            q.push(r[t]);
        }
    }
    for (int i = 0; i < n;i++){
        cout << ans[i];
        if(i!=n-1)
            cout << " ";
    }
    puts("");
    printf("%s", flag ? "YES" : "NO");
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int data;
        cin >> data;
        ins(root, data);
    }
    bfs(root);
    return 0;
}