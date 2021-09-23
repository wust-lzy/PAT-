#include <bits/stdc++.h>
using namespace std;

const int N = 310;
typedef pair<string, string> pss;
unordered_map<string, int> mp;

bool e[N][N];
vector<int> boys, girls;
int n, m, idx, k;
string num[N];
int main()
{
    cin >> n >> m;
    char as[N], bs[N];
    while (m--)
    {
        string a, b;
        scanf("%s%s", as, bs);
        a = as, b = bs;
        string x = a, y = b;
        if(x.size()==5)
            x = x.substr(1);
        if(y.size()==5)
            y = y.substr(1);
        if(mp.count(x)==0)
            mp[x] = ++idx, num[idx] = x;
        if (mp.count(y) == 0)
            mp[y] = ++idx, num[idx] = y;
        int px = mp[x], py = mp[y];
        e[px][py] = e[py][px] = 1;

        if(a[0]!='-')
            boys.push_back(px);
        else
            girls.push_back(px);
        if(b[0]!='-')
            boys.push_back(py);
        else
            girls.push_back(py);
    }
    sort(boys.begin(), boys.end());
    boys.erase(unique(boys.begin(), boys.end()), boys.end());
    sort(girls.begin(), girls.end());
    girls.erase(unique(girls.begin(), girls.end()), girls.end());
    cin >> k;
    while(k--)
    {
        vector<pss> res;
        string x, y;
        scanf("%s%s", as, bs);
        x = as, y = bs;
        vector<int> p = boys, q = boys;
        if(x[0]=='-')
            p = girls, x = x.substr(1);
        if(y[0]=='-')
            q=girls, y = y.substr(1);
        int a = mp[x], b = mp[y];

        for(int c:p){
            for(int d:q){
                if(c!=a&&c!=b&&d!=a&&d!=b&&e[a][c]&&e[c][d]&&e[d][b])
                    res.push_back({num[c], num[d]});
            }
        }
        sort(res.begin(), res.end());
        printf("%d\n", res.size());
        for(auto p:res)
            printf("%s %s\n", p.first.c_str(), p.second.c_str());
    }
    return 0;
}