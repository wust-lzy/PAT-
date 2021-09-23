#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010;
double a[N], b[N], c[N * 2];
int n, k;
void input(double *a)
{
    cin >> k;
    while(k--)
    {
        int ex;
        double co;
        cin >> ex >> co;
        a[ex] += co;
    }
}
int main()
{
    input(a);
    input(b);
    int cnt = 0;
    for (int i = 0; i < N; i++)//多项式乘法
        for (int j = 0; j < N;j++)
            c[i + j] += a[i] * b[j];//指数相加 i+j，系数相乘 
    for (int i = 2*N - 2; i >= 0;i--)
        if(c[i])
            cnt++;
    cout << cnt;
    if(cnt)
        for (int i = 2*N - 2; i >= 0;i--)
        {
            if(c[i])
                printf(" %d %.1lf", i, c[i]);
        }
    return 0;
}