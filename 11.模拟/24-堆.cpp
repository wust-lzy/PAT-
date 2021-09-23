#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N];
int t, n;
void post(int idx)
{
    if(idx>n)
        return;
    post(2 * idx);
    post(2 * idx + 1);
    printf("%d%s", a[idx], idx == 1 ? "" : " ");
}
int main()
{
    cin >> t >> n;
    while(t--){
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        bool lt = 0, gt = 0;
        for (int i = 2; i <= n; i++)
        {
            if(a[i/2]>a[i])//父节点大于子节点
                gt = 1;
            else
                lt = 1;
        }
        if(lt&&gt)
            puts("Not Heap");
        else if(lt)
            puts("Min Heap");
        else
            puts("Max Heap");
        post(1);
        puts("");
    }
    return 0;
}