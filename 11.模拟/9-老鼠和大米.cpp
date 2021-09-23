#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int weight[N];
int n, k;
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
    cin >> n >> k;
    vector<int> ans(n),order(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n;i++)
        cin >> order[i];

    while(order.size()>1)//模拟不断竞争的过程
    {
        vector<int> next;
        int groups = (order.size() + k - 1) / k;//本轮一共有多少组
        for (int i = 0; i < groups;i++){
            int maxn = -1, idx = -1;
            int st = i * k, ed = min((int)order.size(), (i + 1) * k);
            for (int j = st; j < ed; j++)
            {
                if(weight[order[j]]>maxn){
                    maxn = weight[order[j]];
                    idx = j;
                }
            }
            for (int j = st; j < ed; j++){//被淘汰的老鼠排名为groups+1
                if(j!=idx)
                    ans[order[j]] = groups + 1;
                else
                    next.push_back(order[j]);
            }
        }
        order = next;
    }
    ans[order[0]] = 1;
    output(ans);
    return 0;
}