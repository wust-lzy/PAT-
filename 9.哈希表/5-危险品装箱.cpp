#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1e4+10;
typedef pair<int, int> pii;
pii all[N];
unordered_set<int> vis;


int main()
{
    FAST;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n;i++)
        cin >> all[i].first >> all[i].second;
    while(q--){
        int k, x;
        cin >> k;
        vis.clear();
        while(k--){
            cin >> x;
            vis.insert(x);
        }
        bool flag = 1;
        for (int i = 0; i < n;i++){
            if(vis.count(all[i].first)&&vis.count(all[i].second))
            {
                flag = 0;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}