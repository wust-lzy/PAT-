#include <bits/stdc++.h>
using namespace std;

void output(set<int>&p)
{
    cout<<p.size()<<endl;
    bool fir = 1;
    for (auto&e:p){
        if(fir)
            fir = 0;
        else
            printf(" ");
        printf("%d", e);
    }
}
int f(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main()
{
    set<int> S;
    int n;
    cin>>n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        S.insert(f(x));
    }
    output(S);
    return 0;
}