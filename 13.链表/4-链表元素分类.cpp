#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int h, e[N], ne[N];
int main()
{
    scanf("%d %d %d", &h, &n, &k);
    for (int i = 0; i < n;i++){
        int ad, key, next;
        scanf("%d %d %d", &ad, &key, &next);
        e[ad] = key, ne[ad] = next;
    }
    vector<int> a, b, c;
    for (int i = h; i!=-1;i=ne[i]){
        int val = e[i];
        if(val<0)
            a.push_back(i);
        else if(val>=0&&val<=k)
            b.push_back(i);
        else
            c.push_back(i);
    }
    a.insert(a.end(), b.begin(), b.end());
    a.insert(a.end(), c.begin(), c.end());
    for (int i = 0; i < a.size();i++){
        printf("%05d %d ", a[i], e[a[i]]);
        if(i!=a.size()-1)
            printf("%05d\n", a[i + 1]);
        else
            printf("-1\n");
    }
        return 0;
}