#include <bits/stdc++.h>
using namespace std;

struct school
{
    string name;
    int ns,score[3];
    double total;
    school() {
        ns = 0;
        memset(score, 0, sizeof score);
    }
    void cal(){
        total = (1.0*score[0] / 1.5) + score[1] +  (1.5*score[2]);
        total = (int)total;
    }
    bool operator<(const school &t)const{
        if(total!=t.total)
            return total > t.total;
        else if(ns!=t.ns)
            return ns < t.ns;
        else
            return name < t.name;
    }
};
unordered_map<string,school>all;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        string id, sch;
        int grade;
        cin >> id >> grade >> sch;
        transform(sch.begin(), sch.end(), sch.begin(), ::tolower);
        if(id[0]=='B')
            all[sch].score[0] += grade;
        else if(id[0]=='A')
            all[sch].score[1] += grade;
        else
            all[sch].score[2] += grade;
        all[sch].ns++;
        all[sch].name = sch;
    }
    vector<school> ans;
    for(auto &sch:all){
        sch.second.cal();
        ans.push_back(sch.second);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0,rank=1; i < ans.size();i++)
    {
        if(i>0)
            rank = ans[i].total == ans[i - 1].total ? rank : i + 1;
        printf("%d %s %d %d\n",rank,ans[i].name.c_str(), (int)ans[i].total, ans[i].ns);
    }
    return 0;
}