#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 100010;

struct stu
{
    int id;
    string name;
    int grade;
}students[N];
int main()
{
    FAST;
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n;i++)
        cin >> students[i].id >> students[i].name >> students[i].grade;
    if(c==1)    //按照id排序
        sort(students, students + n, [](stu &a, stu &b) 
             { return a.id < b.id; });
    else if(c==2)
        sort(students, students + n, [](stu &a, stu &b)
             {
                 if (a.name != b.name)
                     return a.name < b.name;
                 return a.id < b.id;
             });
    else//成绩排序
        sort(students, students + n, [](stu &a, stu &b)
             {  
                 if(a.grade!=b.grade)
                     return a.grade < b.grade;
                 return a.id < b.id;
             });
    for (int i = 0; i < n;i++)
        printf("%06d %s %d\n", students[i].id, students[i].name.c_str(), students[i].grade);
    return 0;
}