#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, m;
struct Person
{
    int arrive_time;
    int service_time;

    bool operator< (const Person&t)const
    {
        return arrive_time < t.arrive_time;//根据到达时间排序
    }
}persons[N];

int main()
{
    scanf("%d %d", &n, &m); //人数和窗口数
    for (int i = 0; i < n; i++)
    {
        int hour, minute, second, service_time;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &service_time);
        service_time = min(service_time * 60, 3600);//最长一个小时
        persons[i] = {hour * 3600 + minute * 60 + second,service_time};
    }

    priority_queue<int, vector<int>, greater<int> > windows;   //小根堆
    for (int i = 0; i < m;i++)//安排m个窗口
        windows.push(8 * 3600);
    sort(persons, persons + n);
    double sum = 0;//等待的总时间
    int cnt = 0;//服务的人数

    for (int i = 0; i < n;i++)
    {
        Person p = persons[i];
        int w = windows.top();
        windows.pop();
        if(p.arrive_time>17*3600)//如果大于五点 直接推出
            break;
        
        int start_time = max(p.arrive_time, w);//开始时间取到达时间和窗口结束时间最大值
        sum += start_time - p.arrive_time;
        cnt++;
        windows.push(start_time + p.service_time);
    }

    printf("%.1lf", sum / cnt/60);
    return 0;
}