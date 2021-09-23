#include<bits/stdc++.h>
using namespace std;
struct stu
{
    int ge, gi, total,rank,id;
    int choice[10];//填补志愿
    bool operator <(const stu &s)const{
        if (total!=s.total)
            return total > s.total;
        return ge > s.ge;
    }
};
struct school
{
    int num, lastrank;//名额，录取学生最低排名
    vector<int> stuID;//录取学生名单
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<school> sch(m);
    vector<stu> students(n);
    for (int i = 0; i < m; i++)//m个学校
        scanf("%d", &sch[i].num);
    for (int i = 0; i < n; i++){
        students[i].id = i;
        scanf("%d %d", &students[i].ge, &students[i].gi);
        students[i].total = students[i].ge + students[i].gi;
        for (int j = 0; j < k; j++)//输入学生k个志愿
            scanf("%d", &students[i].choice[j]);
    }
    sort(students.begin(), students.end());
    students[0].rank = 1;
    for (int i = 1; i < n; i++){//更新学生rank
        if (students[i].total==students[i-1].total&&students[i].ge==students[i-1].ge)
            students[i].rank = students[i - 1].rank;
        else
            students[i].rank = i + 1;
    }
    for (int i = 0; i < n; i++)//n个学生，判断录取情况
    {
        for (int j = 0; j<k; j++){
            int index = students[i].choice[j];
            if (sch[index].lastrank==students[i].rank||sch[index].num>0){
                sch[index].stuID.push_back(students[i].id);
                sch[index].lastrank = students[i].rank;
                sch[index].num--;
                break;//学生被录用 退出当前学校
            }       
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (!sch[i].stuID.empty()){
            sort(sch[i].stuID.begin(), sch[i].stuID.end());
            for (int j = 0; j<sch[i].stuID.size(); j++)
            {
                printf("%d", sch[i].stuID[j]);
                if (j!=sch[i].stuID.size()-1)
                    printf(" ");          
            }
        }
        printf("\n");
    }
    return 0;
}
