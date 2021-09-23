#include <bits/stdc++.h>
using namespace std;


int cal(int n)
{
    int ans = 0, a = 1, left, right, now;
    while(n/a){
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;
        if(now==0)//左边的范围是0-left-1 右边是a
            ans += left * a;
        else if(now==1)//分两种情况
            ans += left * a + right + 1;
        else if(now>1)//左边0-left 右边0～a-1
            ans += (left + 1) * a;
        a *= 10;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << cal(n);
    return 0;
}