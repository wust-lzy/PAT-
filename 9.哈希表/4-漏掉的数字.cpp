#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
unordered_set<int> S;

int main()
{
    int n;
    FAST;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        if(x>0)
            S.insert(x);
    }
    for (int i = 1;;i++)
    if(!S.count(i)){
        cout << i;
        break;
    }
        return 0;
}