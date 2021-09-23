#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi;
const int N = 1e4+10;

int n, k;
string line[N];
int main()
{
    cin >> n >> k;
    vector<psi> all(n);
    for (int i = 0; i < n;i++)
        cin >> all[i].first >> all[i].second;
    sort(all.begin(), all.end(), [](psi &a, psi &b) {
        if(a.second!=b.second)
            return a.second > b.second;
        return a.first < b.first;
    });
    for (int i = 0,j=0; i < k;i++){
        int len = n / k;
        if(i==0){//特判最后一排
            len += n % k;
        }
        for (int r = len / 2 + 1, l = r - 1; l > 0 || r <= len;r++,l--){
            if(r<=len)//先右后左
                line[r] = all[j++].first;
            if(l>0)
                line[l] = all[j++].first;
        }
        cout << line[1];
        for (int t = 2; t <= len;t++)
            cout << " " << line[t];
        cout << endl;
    }
        return 0;
}