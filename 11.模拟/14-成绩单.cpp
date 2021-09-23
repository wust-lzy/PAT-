#include <bits/stdc++.h>
using namespace std;

struct Stu
{
    string name, id;
    int grade;
    Stu(string a="",string b="",int c=0):name(a),id(b),grade(c){}
    bool operator <(const Stu&s){
        return grade > s.grade;
    }
};
int main()
{
    int n, low, high;
    cin >> n;
    vector<Stu> book(n), ans;
    for (int i = 0; i < n; i++)
        cin >> book[i].name >> book[i].id >> book[i].grade;
    cin >> low >> high;
    for (int i = 0; i < n; i++)
    {
        if (book[i].grade>=low&&book[i].grade<=high)
            ans.push_back(Stu(book[i].name, book[i].id, book[i].grade));
    }
    sort(ans.begin(), ans.end());
    if (!ans.empty()){
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].name << " " << ans[i].id << "\n";
    }
    else
        cout << "NONE";
    return 0;
}
