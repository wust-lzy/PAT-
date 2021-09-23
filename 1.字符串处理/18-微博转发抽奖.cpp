#include <bits/stdc++.h>
using namespace std;

unordered_set<string> S;
int main()
{
    int m, n, s;
    vector<string> all(m);
    vector<string> ans;
    for (int i = 0; i < m;i++)
        cin >> all[i];
    int idx = s - 1;
    while(idx<m){
        if(!S.count(all[idx])){
            S.insert(all[idx]);
            ans.push_back(all[idx]);
        }
        else{
            idx++;
            continue;
        }
        idx += n;
    }
    for(string&e:ans)
        cout << e << endl;
    if(ans.empty())
        cout << "Keep going...";
        return 0;
}