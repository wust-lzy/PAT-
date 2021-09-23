#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 110;
int a[N], b[N], n;

void donwjust(int low,int high)
{
    int i = low, j = i * 2;
    while (j<=high)
    {
        if(j+1<=high&&b[j+1]>b[j])
            j++;
        if(b[j]>b[i])
        {
            swap(b[j], b[i]);
            i = j;
            j = i * 2;
        }
        else
            break;
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    int idx = 1;
    while(b[idx]<=b[idx+1])
        idx++;
    bool flag = true;
    idx++;
    for (int i = idx; i <= n; i++)
    {
        if(a[i]!=b[i])
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        puts("Insertion Sort");
        sort(b+1, b + idx + 1);
    }
    else
    {
        puts("Heap Sort");
        idx = n;
        while(idx>2&&b[idx]>=b[1])
            idx--;
        swap(b[1], b[idx]);
        donwjust(1, idx - 1);
    }
    for (int i = 1; i <= n;i++)
    {
        cout << b[i];
        if(i!=n)
            cout << " ";
    }
        return 0;
}