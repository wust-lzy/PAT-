#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, f = 0, sum = 0, t;
    cin >> n;
    while(n--)
    {
        cin >> t;
        if(t>f)
        {
            sum += (t - f) * 6;
            sum += 5;
        }
        else if(t<f)
        {
            sum += (f - t) * 4;
            sum += 5;
        }
        else
            sum += 5;
        f = t;
    }
    cout << sum;
    return 0;
}