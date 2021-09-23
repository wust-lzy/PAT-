#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1010;
typedef pair<int, int> pii;
int n, m, k, cnt;
int father[N];
vector<pii> e;
void output(vector<int>&p)
{
    for (int i = 0; i < p.size();i++){
        printf("%d", p[i]);
        if(i!=p.size()-1)
            printf(" ");
    }
}
int findfather(int x)
{
    if(father[x]==x)
        return x;
    int f = findfather(father[x]);
    father[x] = f;
    return f;
}

void Union(int a,int b)
{
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa!=fb){
        father[fa] = fb;
        cnt--;
    }
}
int main()
{
    FAST;
    cin >> n >> m >> k;
    e.resize(m);
    for (int i = 0; i < m;i++)
        cin >> e[i].first >> e[i].second;
    while(k--){
        int x;
        cin >> x;//丢弃的点
        for (int i = 1; i <= n;i++)//初始化
            father[i] = i;
        cnt = n-1;//有n-1个集合,x被损坏
        for (pii&item:e){//遍历每一条边,加到一个集合
            if(item.first!=x&&item.second!=x)
                Union(item.first, item.second);
        }
        cout << cnt - 1 << endl;//剩余集合数-1
    }
        return 0;
}