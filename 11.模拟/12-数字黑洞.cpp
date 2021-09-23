#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    while (n<1000)
        n *= 10;
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    sort(num.begin(),num.end());
    int maxn=num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];
    int minn=num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
    printf("%04d - %04d = %04d\n", maxn, minn, maxn - minn);
    return maxn - minn;
}
int main()
{
    int n;
    cin >> n;
    while(n!=0)
    {
        n = func(n);
        if (n==6174)
            break;
    }
    return 0;
}