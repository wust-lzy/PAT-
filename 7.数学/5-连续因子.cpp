#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    int max_len = 0, idx = -1;
    for (int i = 2; i <= n / i;i++){
        if(n%i==0){
            long long temp = n;
            int j = i;
            while(temp%j==0){
                temp /= j;
                j++;
            }
            if(j-i>max_len){
                max_len = j - i;
                idx = i;
            }
        }
    }
    if(max_len==0){//本身是质数
        max_len=1;
        idx=n;
    }
    cout<<max_len<<endl;
    for (int i = 0; i < max_len;i++){
        cout << i+idx;
        if(i!=max_len-1)
            cout << '*';
    }
        return 0;
}