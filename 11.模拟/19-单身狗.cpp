#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> cp;
set<int> S;
int main()
{
    int n, m;
    cin >> n;
    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        cp[a] = b;
    }
    cin >> m;
    while(m--){
        int x;
        scanf("%d", &x);
        S.insert(x);
    }
    for(auto&e:cp){
        if(S.count(e.first)&&S.count(e.second)){
            S.erase(e.first);
            S.erase(e.second);
        }
    }
    cout << S.size() << endl;
    bool fir = 1;
    for(const int&e:S){
        if(fir){
            fir = 0;
            printf("%05d", e);
        }
        else
            printf(" %05d", e);
    }
    return 0;
}