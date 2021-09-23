#include <bits/stdc++.h>
using namespace std;

const int N = 210, inf = 1e8;
int e[N][N];//邻接矩阵寸图
int n, m, k;
unordered_set<int> S;//用集合存储点数
int main()
{
    fill(e[0], e[0] + N * N, inf);//初始化为无穷大
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[a][b] = e[b][a] = min(e[a][b], c);//无向图
    }
    cin >> k;
    int minn = inf, idx;
    for (int i = 1; i <= k; i++)
    {
        S.clear();
        int q, sum = 0;
        cin >> q;
        vector<int> temp(q);
        for (int j = 0; j < q;j++)
        {
            cin >> temp[j];
            S.insert(temp[j]);
        }
        bool flag = 1;
        for (int j = 0; j < q - 1;j++){
            if(e[temp[j]][temp[j+1]]==inf){//有不可达边
                flag = 0;
                break;
            }
            sum += e[temp[j]][temp[j + 1]];
        }
        if(!flag){//输出NA
            printf("Path %d: NA (Not a TS cycle)\n", i);
        }
        else if(S.size()!=n||temp[0]!=temp[q-1])//没有遍历所有点，或者不是回路
            printf("Path %d: %d (Not a TS cycle)\n", i, sum);
        else{
            if(sum<minn){
                minn = sum;
                idx = i;
            }
            if(q==n+1)//遍历了所有点，起点等于终点，且点数刚好是n+1
                printf("Path %d: %d (TS simple cycle)\n", i, sum);
            else
                printf("Path %d: %d (TS cycle)\n", i, sum);
        }
    }
    printf("Shortest Dist(%d) = %d", idx, minn);
    return 0;
}