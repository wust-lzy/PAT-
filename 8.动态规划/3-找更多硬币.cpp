#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 10010, M = 105;
int v[N];
bool f[N][M];//前i件物品，体积为j 是否能达到
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)//求最小字典序
        cin >> v[i];//因为求方案是从后往前，所以要从大到小排序
    sort(v + 1, v + 1 + N, greater<int>());
    f[0][0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            f[i][j] = f[i - 1][j];//第i件物品没有选
            if(j>=v[i])//背包装的下第i件物品,选一下
                f[i][j] |= f[i - 1][j - v[i]];
        }
    }
    if(!f[n][m])
        puts("No Solution");
    else{
        bool fir = 1;
        while(n){//每件物品一件件看，是否选了
            if(m>=v[n]&&f[n-1][m-v[n]]){
                if(fir)
                    fir = 0;
                else
                    cout << " ";
                cout << v[n];
                m -= v[n];
            }
        n--;
        }

    }
    return 0;
}
    