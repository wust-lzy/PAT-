#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(int x)
{
    if(x<2)
        return 0;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
int main()
{
    int l, k;
    string s;
    cin >> l >> k >> s;
    for (int i = 0; i <= l - k;i++)
    {
        string temp = s.substr(i, k);
        if(isprime(stoi(temp)))
        {
            cout << temp;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}