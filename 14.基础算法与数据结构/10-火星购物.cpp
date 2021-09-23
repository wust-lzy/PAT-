#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
int a[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    int dir = 1e8, sum = 0;//保存最小的差和临时和
    vector<pii> ans;
    for (int i = 1, j = 1; j <= n;j++){
        sum += a[j];
        while(sum-a[i]-m>=0)//滑动窗口
            sum -= a[i++];
        if(sum-m>=0&&sum-m<dir){
            dir = sum - m;
            ans.clear();
            ans.push_back({i, j});
        }
        else if(sum-m==dir)
            ans.push_back({i, j});
    }
    for(pii&p:ans)
        printf("%d-%d\n", p.first, p.second);
    return 0;
}