#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N];//记录每个数字的位置

int main()
{
    int cnt = 0, n, x;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &x);
        a[x] = i;
    }
    for (int i = 0; i < n;i++){
        if(a[i]!=i){
            while(a[0]!=0){
                swap(a[0], a[a[0]]);
                cnt++;
            }
            if(a[i]!=i){
                swap(a[0], a[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}