#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

const string names[4] = {"A", "C", "M", "E"};
vector<int> grade[4];                    //对应a,c,m,e
unordered_map<string, vector<int>> book; //判断学生id对应的4门成绩
int n, m;

int get_rank(vector<int>&a,int p)//二分求出每个成绩的排名
{
    int l = 0, r = a.size()-1;
    while(l<r)
    {
        int mid = l + r >> 1;
        if(a[mid]<=p)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n;i++)
    {
        int t[4] = {0};
        string id;
        cin >> id;
        for (int j = 1; j < 4; j++)
        {
            cin >> t[j];
            t[0] += t[j];
        }
        t[0] = round(t[0] / 3.0);
        for (int j = 0; j < 4;j++)
        {
            book[id].push_back(t[j]);//每个学生对应的成绩
            grade[j].push_back(t[j]);//统计每门成绩表
        }
    }
    for (int i = 0; i < 4;i++)//从大到小排序
        sort(grade[i].begin(), grade[i].end(),greater<int>());
    while(m--)
    {
        string id;
        cin >> id;
        if(!book.count(id))
        {
            puts("N/A");
            continue;
        }
        int cnt = 10000;
        string c;
        for (int i = 0; i < 4;i++)
        {
            int rank = get_rank(grade[i], book[id][i]);
            if(rank<cnt)
            {
                cnt = rank;
                c = names[i];
            }
        }
        cout << cnt+1 << " " << c << endl;
    }
    return 0;
}