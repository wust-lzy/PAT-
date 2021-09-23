#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int h1,h2,ne[N], n;
char e[N];
bool vis[N];
int main()
{
    scanf("%d %d %d", &h1, &h2, &n);
    for (int i = 0; i < n;i++){
        int ad, next;
        char c;
        scanf("%d %c %d", &ad, &c, &next);
        e[ad] = c, ne[ad] = next;
    }
    for (int i = h1; i != -1;i=ne[i])
        vis[i] = 1;
    for (int i = h2; i != -1;i=ne[i]){
        if(vis[i]){
            printf("%05d", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}