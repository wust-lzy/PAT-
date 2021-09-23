#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 25;

int l[N], r[N], v[N], h[N], idx;

void update(int u)//更新高度
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
    if(!u)
        u = ++idx, v[u] = data;
    else if(data<v[u]){
        ins(l[u], data);
        if(get_balance(u)==2){
            if(get_balance(l[u])==1)//LL型
                R(u);
            else{//LR型
                L(l[u]);
                R(u);
            }
        }
    }else{
        ins(r[u], data);
        if(get_balance(u)==-2){
            if(get_balance(r[u])==-1)//RR型
                L(u);
            else{//RL型
                R(r[u]);
                L(u);
            }
        }
    }
    update(u);//调整高度
}
int main()
{
    int n, root = 0;
    cin >> n;
    while(n--)
    {
        int data;
        cin >> data;
        ins(root, data);
    }
    cout << v[root] << endl;
    return 0;
}