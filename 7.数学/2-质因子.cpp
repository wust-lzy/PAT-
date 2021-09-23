#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
bool fir = 1;
void divide(ll n)
{
    cout << n << "=";
    for (int i = 2; i <= n / i; i++)
    {
        if(n%i==0){
            if(fir)
                fir = 0;
            else
                cout << "*";
            int cnt = 0;
            while(n%i==0){
                cnt++;
                n /= i;
            }
            cout << i;
            if(cnt>1)
                cout << "^" << cnt;
        }
    }
    if(n>1)
        cout << "*" << n;
}
int main()
{
    cin >> n;
    if(n==1)
        cout << "1=1" << endl;
    else
        divide(n);
    return 0;
}