#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
int n;
int h, e[N], ne[N];
int main()
{
    scanf("%d %d", &h, &n);
    for (int i = 0; i < n;i++){
        int ad, key, next;
        scanf("%d %d %d", &ad, &key, &next);
        e[ad] = key, ne[ad] = next;
    }
    vector<int> a, b;
    for (int i = h; ~i;i=ne[i]){
        int val = abs(e[i]);
        if(vis[val])
            b.push_back(i);
        else{
            vis[val] = 1;
            a.push_back(i);
        }
    }
    for (int i = 0; i < a.size();i++){
        printf("%05d %d ", a[i], e[a[i]]);
        if(i!=a.size()-1)
            printf("%05d\n", a[i + 1]);
        else
            puts("-1");
    }
    for (int i = 0; i < b.size();i++){
        printf("%05d %d ", b[i], e[b[i]]);
        if(i!=b.size()-1)
            printf("%05d\n", b[i + 1]);
        else
            puts("-1");
    }
        return 0;
}