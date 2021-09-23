#include <bits/stdc++.h>
using namespace std;

struct Person
{
    string name;
    int age, money;
    bool operator<(const Person&p)const{
        if(money!=p.money)
            return money > p.money;
        if(age!=p.age)
            return age < p.age;
        return name < p.name;
    }
};
const int N = 210;
int n, k, idx[N];
vector<Person> ages[N];

int main()
{
    char name[10];
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n;i++){
        int age, mon;
        scanf("%s %d %d", name, &age, &mon);
        ages[age].push_back({name, age, mon});
    }

    for(vector<Person>&p:ages)
        sort(p.begin(), p.end());

    int m, minn, maxn;
    for (int i = 1; i <= k;i++){
        printf("Case #%d:\n", i);
        scanf("%d %d %d", &m, &minn, &maxn);

        memset(idx, 0, sizeof idx);
        bool exist = false;
        while(m--)
        {
            int t = -1;
            for (int j = minn; j <= maxn;j++){//从minn~maxn中选一个最大值
                if(idx[j]<ages[j].size()){
                    if(t==-1||ages[j][idx[j]]< ages[t][idx[t]])
                        t = j;
                }
            }
            if(t==-1)
                break;
            auto &p = ages[t][idx[t]];
            idx[t]++;
            printf("%s %d %d\n", p.name.c_str(),p.age, p.money);
            exist = 1;
        }
        if(!exist)
            printf("None\n");
    }
    return 0;
}