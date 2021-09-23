#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second

bool check(pii& a,pii& b)//任意两个皇后位置对比
{
    if(a.x==b.x||a.y==b.y)
        return 0;
    if (abs(a.x-b.x)==abs(a.y-b.y))
        return 0;
    return 1;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k,t;
        scanf("%d", &k);
        vector<pii >v(k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &t);
            v[i] = pii(t, i + 1);
        }
        int flag = 1;
        for (int i = 0; i < k&&flag; i++)
        {
            for (int j = i + 1; j < k;j++)
            {
                if(!check(v[i],v[j]))
                {
                    flag = 0;
                    break;
                }
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}