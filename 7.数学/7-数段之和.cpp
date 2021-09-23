#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

typedef long long ll;
int main()
{
    int n;
    cin >> n;
    long double sum = 0;
    for (int i = 1; i <= n;i++){
        long double x;
        scanf("%Lf",&x);
        int left = i, right = n - i + 1;
        sum += x* left * right;
    }
    printf("%.2Lf", sum);
    return 0;
}