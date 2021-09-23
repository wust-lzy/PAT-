#include <bits/stdc++.h>
using namespace std;

int nc, np, x;

int main()
{
    vector<int> a1, a2, b1, b2;
    cin >> nc;
    for (int i = 0; i < nc;i++){
        scanf("%d", &x);
        if(x>0)
            a1.push_back(x);
        else if(x<0)
            a2.push_back(x);
    }
    cin >> np;
    for (int i = 0; i < np;i++){
        scanf("%d", &x);
        if(x>0)
            b1.push_back(x);
        else if(x<0)
            b2.push_back(x);
    }
    sort(a1.begin(), a1.end(), greater<int>());
    sort(a2.begin(),a2.end());
    sort(b1.begin(), b1.end(), greater<int>());
    sort(b2.begin(),b2.end());
    int i = 0, j = 0, ans = 0;
    while(i<a1.size()&&j<b1.size()){//正数和正数相乘
        printf("%d*%d\n", a1[i], b1[j]);
        ans += a1[i++] * b1[j++];
    }
    i = 0, j = 0;
    while(i<a2.size()&&j<b2.size()){//负数和负数相乘
        printf("%d*%d\n", a2[i], b2[j]);
        ans += a2[i++] * b2[j++];
    }
    cout << ans;
    return 0;
}