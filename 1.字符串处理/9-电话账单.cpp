#include<bits/stdc++.h>

using namespace std;

const int N = 1010, M = 31 * 1440 + 10;
int n, cost[24];//每个时间段的话费
double sum[M];//从1号00:00到每个时刻花的钱

struct Record
{
    int minutes;
    string status;
    string format_time;

    bool operator <(const Record&t)const
    {
        return minutes < t.minutes;
    }
};

map<string, vector<Record>> persons;

int main()
{
    for (int i = 0; i < 24;i++)//输入每个时间段的话费
        cin >> cost[i];
    for (int i = 1; i < M;i++)//初始化前缀和
        sum[i] = sum[i - 1] + cost[(i - 1) % 1440 / 60] / 100.0;
    cin >> n;
    char name[25], sta[10],format_time[20];
    int mon, day, hour, minute;
    for (int i = 0; i < n;i++)
    {
        scanf("%s %d:%d:%d:%d %s", name, &mon, &day, &hour, &minute, sta);
        sprintf(format_time, "%02d:%02d:%02d", day, hour, minute);  //保存时间

        int minutes = (day - 1) * 1440 + hour * 60 + minute;
        persons[name].push_back({minutes, sta, format_time});//每个人插入一条记录
        // persons[name].push_back({minutes, sta, format_time});//每个人插入一条记录
    }

    for(auto &p:persons)
    {
        string name = p.first;
        vector<Record> records = p.second;
        sort(records.begin(), records.end());//按照时间排序

        double total = 0;
        for (int i = 0; i+1 < records.size(); i++)
        {
            Record a = records[i], b = records[i + 1];
            if(a.status=="on-line"&&b.status=="off-line")
            {
                if(!total)
                    printf("%s %02d\n", name.c_str(), mon);//输出姓名
                cout << a.format_time << " " << b.format_time;

                double c = sum[b.minutes] - sum[a.minutes];
                printf(" %d $%.2lf\n", b.minutes - a.minutes, c);
                total += c;
            }
        }

        if(total)
            printf("Total amount: $%.2lf\n", total);
    }
    return 0;
}