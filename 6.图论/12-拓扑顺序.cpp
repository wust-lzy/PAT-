#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1010, M = 10010;
int n, m, k;
pii e[M];//记录边
int order[N];//记录顺序
void output(vector<int> &p)
{
    for (int i = 0; i < p.size();i++){
        printf("%d", p[i]);
        if(i!=p.size()-1)
            printf(" ");
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> e[i].first >> e[i].second;

    cin >> k;
    vector<int> ans;
    for (int i = 0; i < k;i++){
        int x;
        for (int j = 0; j < n;j++){//记录序列每个数字的顺序
            cin >> x;
            order[x] = j;
        }
        bool flag = 1;
        for (int j = 0; j < m; j++) //遍历每条边，看每个点是否满足拓扑顺序{
        {
            if(order[e[j].first]>order[e[j].second]){
                flag = 0;
                break;
            }
        }
        if(!flag)
            ans.push_back(i);
    }
    output(ans);
    return 0;
}