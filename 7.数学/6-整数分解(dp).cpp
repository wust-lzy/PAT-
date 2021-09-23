#include <bits/stdc++.h>
using namespace std;

const int N = 410,inf = 1e8;
int f[21][N][N];
int n, k, p;

int quick_pow(int a, int b)
{
    int ans = 1;
    while(b){
        if(b&1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main()
{
    for (int i = 0; i < 21;i++)
        for (int j = 0; j < N;j++)
            for (int k = 0; k < N;k++)
                f[i][j][k] = -inf;
    f[0][0][0] = 0;
    cin >> n >> k >> p;
    int m;
    for (m = 1;;m++){
        int v = quick_pow(m, p);
        if(v>n)
            break;
        for (int i = 0; i <= n;i++){
            for (int j = 0; j <= k;j++){
                f[m][i][j] = f[m - 1][i][j];
                if(i>=v&&j)
                    f[m][i][j] = max(f[m][i][j], f[m][i - v][j - 1] + m);
            }
        }
    }
    m--;
    // cout<<f[m][n][k];
    if(f[m][n][k]<0)
        puts("Impossible");
    else{
        printf("%d = ", n);
        bool fir = 1;
        while(m){
            int v = quick_pow(m, p);
            while(n>=v&&k&&f[m][n-v][k-1]+m==f[m][n][k]){
                if(fir)
                    fir = 0;
                else
                    printf(" + ");
                printf("%d^%d", m, p);
                n -= v, k--;
            }
            m--;
        }
    }
    return 0;
}