#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

struct node
{
    int h, x, y;
};
const int N = 1300, M = 130, H = 65;
const int go[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int g[H][N][M];
int n, m, l, t;
int bfs(int h,int x,int y)//三维求连通块
{
    int cnt = 0;
    queue<node> q;
    q.push({h,x,y});
    g[h][x][y] = 0;
    
    while(!q.empty()){
        node t = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6;i++){
            int dl=t.h + go[i][0];
            int dx=t.x + go[i][1];
            int dy=t.y + go[i][2];
            if(dl>=0&&dl<l && dx>=0&&dx<n && dy>=0&&dy<m&&g[dl][dx][dy]){
                g[dl][dx][dy] = 0;
                q.push({dl, dx, dy});
            }
        }
    }
    return cnt >= t ? cnt : 0;
}
int main()
{
    FAST;
    cin >> n >> m >> l >> t;
    for (int i = 0; i < l;i++){
        for (int j = 0; j < n;j++){
            for (int k = 0; k < m;k++){
                cin >> g[i][j][k];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < l;i++){
        for (int j = 0; j < n;j++){
            for (int k = 0; k < m;k++){
                if(g[i][j][k])
                    ans += bfs(i, j, k);
            }
        }
    }
    cout << ans;
    return 0;
}