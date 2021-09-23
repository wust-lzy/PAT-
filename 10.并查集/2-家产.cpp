#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 10010;

int n;
int father[N], cnt[N], hc[N], ha[N];
bool vis[N];
struct edge
{
    int a, b;
}e[N];
struct family
{
    int id, cnt, hc, ha;
    bool operator<(const family&t)const{
        if(ha*t.cnt!=t.ha*cnt)
            return ha * t.cnt > t.ha * cnt;
        return id < t.id;
    }
};
int findfather(int x)
{
    if(x==father[x])
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}
int main()
{
    cin >> n;
    int m = 0;
    for (int i = 0; i < n;i++){
        int id, fa, mo, k;
        cin >> id >> fa >> mo >> k;
        vis[id] = 1;
        if(fa!=-1)
            e[m++] = {id, fa};
        if(mo!=-1)
            e[m++] = {id, mo};
        for (int j = 0; j < k;j++){
            int son;
            cin >> son;
            e[m++] = {id, son};
        }
        cin >> hc[id] >> ha[id];
    }
    for (int i = 0; i < N;i++)
        father[i] = i, cnt[i] = 1;
    for (int i = 0; i < m;i++){
        int a = e[i].a, b = e[i].b;

        vis[a] = vis[b] = 1;
        int fa = findfather(a), fb = findfather(b);
        if(fa!=fb){
            if(fb>fa)
                swap(fa, fb);
            cnt[fb] += cnt[fa];
            hc[fb] += hc[fa];
            ha[fb] += ha[fa];
            father[fa] = fb;
        }
    }
    vector<family> ans;
    for (int i = 0; i < N;i++)
    if(vis[i]&&father[i]==i)
        ans.push_back({i, cnt[i], hc[i], ha[i]});

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto &item:ans)
        printf("%04d %d %.3lf %.3lf\n", item.id, item.cnt, 1.0*item.hc/item.cnt, 1.0*item.ha/item.cnt);
    return 0;
}