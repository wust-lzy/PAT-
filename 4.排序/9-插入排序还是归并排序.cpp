#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 110;
int n;
int a[N], b[N];

bool check()
{
    for (int i = 0; i < n;i++)
    if(a[i]!=b[i])
        return 0;
    return 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n;i++)
        cin >> b[i];
    int k = 0;
    while(b[k+1]>b[k])
        k++;
    int idx = k + 1;
    while(a[idx]==b[idx])
        idx++;
    if(idx==n+1){
        puts("Insertion Sort");
        sort(b, b + k + 2);
        for (int i = 0; i < n;i++){
            cout<<b[i];
            if(i!=n-1)
                cout << " ";
        }
    }else{
        puts("Merge Sort");
        k = 1;
        while(!check()){
            k <<= 1;
            for (int i = 0; i < n;i+=k)
                sort(a + i, a + min(n, i + k));
        }
        k <<= 1;
        for (int i = 0; i < n;i+=k)
                sort(a + i, a + min(n, i + k));
        for (int i = 0; i < n;i++){
            cout<<a[i];
            if(i!=n-1)
                cout << " ";
        }
    }
    return 0;
}