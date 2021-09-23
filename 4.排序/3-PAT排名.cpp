#include <bits/stdc++.h>
using namespace std;

const int N = 110;

struct stu
{
    string id;
    int grade, local_num;
    bool operator <(const stu&s){
        if(grade!=s.grade)
            return grade > s.grade;
        return id < s.id;
    }
};

vector<int> local[N];
vector<stu> ans;    //记录总排名
int get_local_rank(vector<int>&a,int p)//二分找到一个学生在考场的排名
{
    int l = 0, r = a.size() - 1;
    while(l<r){
        int mid = l + r >> 1;
        if(a[mid]<=p)
            r = mid;
        else
            l = mid + 1;
    }
    return l + 1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k;j++)
        {
            string id;
            int x;
            cin >> id >> x;
            ans.push_back({id, x, i});
            local[i].push_back(x);
        }
        sort(local[i].begin(), local[i].end(), greater<int>());//总分按从大到小排序
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    int last = 1, idx = ans[0].local_num;//先输出第一条
    printf("%s %d %d %d\n", ans[0].id.c_str(), 1, idx + 1, get_local_rank(local[idx], ans[0].grade));
    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i].id << " ";
        int idx = ans[i].local_num, g = ans[i].grade;
        if(g==ans[i-1].grade)
            cout << last<<" ";
        else
        {
            cout << i + 1 << " ";
            last = i + 1;
        }
        cout << idx + 1 << " ";
        cout << get_local_rank(local[idx], g) << endl;
    }
        return 0;
}