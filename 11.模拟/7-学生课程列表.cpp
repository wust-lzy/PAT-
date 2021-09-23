#include <bits/stdc++.h>
using namespace std;
const int N = 2550;
vector<string> book[N];//每门课程的学生名单
int n, k;
int main()
{
    scanf("%d %d", &n,&k);
    for (int i = 0; i < n;i++)
    {
        char ch[10];
        int cnt;
        scanf("%s %d", ch, &cnt);
        scanf("%d",&cnt);
        while(cnt--)
        {
            int x;
            scanf("%d", &x);
            book[x].push_back(ch); //课程添加学生
        }
    }
    for (int i = 1; i <= k;i++)
    {
        printf("%d %d\n", i, book[i].size());
        sort(book[i].begin(), book[i].end());
        for(string&c:book[i])
            printf("%s\n", c.c_str());
    }
    return 0;
}