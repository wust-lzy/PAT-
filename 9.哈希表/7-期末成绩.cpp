#include <bits/stdc++.h>
using namespace std;


struct stu{
    string id;
    int program, mid, final, g;
    stu():program(-1),mid(-1),final(-1),g(0){}
    void cal()
    {
        if(final>=mid)
            g = final;
        else
            g = round(mid * 0.4 + final * 0.6);
    }
    bool operator <(const stu&t)const{//重载
        if(g!=t.g)
            return g > t.g;
        return id < t.id;
    }
};
unordered_map<string, stu> all;
int main()
{
    int p, m, n;
    cin >> p >> m >> n;
    string id;
    int x;
    for (int i = 0; i < p;i++){
        cin >> id >> x;
        all[id].id = id;
        all[id].program = x;
    }
    for (int i = 0; i < m;i++){
        cin >> id >> x;
        all[id].id = id;
        all[id].mid = x;
    }
    for (int i = 0; i < n;i++){
        cin >> id >> x;
        all[id].id = id;
        all[id].final = x;
    }
    vector<stu> students;
    for(auto&e:all){
        auto stu = e.second;
        stu.cal();
        if(stu.program>=200&&stu.g>=60)
            students.push_back(stu);
    }
    sort(students.begin(), students.end());
    for(auto&stu:students)
        cout << stu.id << " " << stu.program << " " << stu.mid << " " << stu.final << " " << stu.g << endl;
    return 0;
}