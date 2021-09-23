#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010;
double a[N], b[N];
int n, k;
int main()
{
    cin >> k;
    while(k--)
    {
        int ex;
        double co;
        cin >> ex >> co;
        a[ex] += co;
    }
    cin >> k;
    while (k--)
    {
        int ex;
        double co;
        cin >> ex >> co;
        b[ex] += co;
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)//多项式加法
    {
        a[i] += b[i];
        if(a[i])
            cnt++;
    }
    cout << cnt;
    for (int i = N - 1; i >= 0;i--)
    {
        if(a[i])
            printf(" %d %.1lf", i, a[i]);
    }
        return 0;
}