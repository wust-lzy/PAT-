#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 1010;
int cnt[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= 1010; i++)
    {
        if(m-i<=0)
            break;
        if (cnt[i]){
            cnt[i]--;
            if (cnt[m - i]){
                cout << i << " " << m - i << endl;
                return 0;
            }
            cnt[i]++;
        }
    }
    puts("No Solution");
    return 0;
}