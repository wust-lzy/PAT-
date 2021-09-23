#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

unordered_map<string, set<int>> book;//每个学生选了哪些课

int main()
{
    FAST;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k;i++)
    {
        string t;
        int idx, k;
        cin >> idx >> k;
        for (int j = 0; j < k;j++)
        {
            cin >> t;
            book[t].insert(idx);
        }
    }
    for (int i = 0; i < n;i++)//输出查询
    {
        string query;
        cin >> query;
        cout << query;
        if(book[query].empty())
        {
            cout << " 0" << endl;
            continue;
        }
        cout << " " << book[query].size();
        for(const int &e:book[query])
            cout << " " << e;
        cout << endl;
    }
    return 0;
}