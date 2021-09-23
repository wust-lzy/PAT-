#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, k;
int h, e[N], ne[N];
int main()
{
    scanf("%d %d %d", &h, &n, &k);
    for (int i = 0; i < n;i++){
        int ad, data, next;
        scanf("%d %d %d", &ad, &data, &next);
        e[ad] = data, ne[ad] = next;
    }
    vector<int> ans;
    for (int i = h; i != -1;i=ne[i])
        ans.push_back(i);
    for (int i = 0; i < ans.size() / k;i++){//反转地址
        reverse(ans.begin() + i * k, ans.begin() + (i + 1) * k);
    }
    for (int i = 0; i < ans.size();i++){
        printf("%05d %d ", ans[i], e[ans[i]]);
        if(i==ans.size()-1)
            puts("-1");
        else
            printf("%05d\n", ans[i+1]);
    }
        return 0;
}