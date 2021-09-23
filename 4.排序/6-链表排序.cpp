#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 100010;
struct node
{
    int address,key,next;
    bool operator<(const node &t)
    {
        return key < t.key;
    }
};

int main()
{
    FAST;
    int n,head;
    cin >> n >> head;
    unordered_map<int, node> map;
    while(n--)
    {
        int ad,key, ne;
        cin >> ad >> key >> ne;
        map[ad] = {ad, key, ne};
    }
    vector<node> ans;
    for (int i = head; i != -1;i=map[i].next)//将节点存入vector里面
        ans.push_back(map[i]);
    printf("%d", ans.size());
    if(ans.empty())
        puts(" -1");
    else{
        sort(ans.begin(), ans.end());//排序
        printf(" %05d\n", ans[0].address);
        for (int i = 0; i < ans.size();i++)
        {
            if(i==ans.size()-1)
                printf("%05d %d -1\n", ans[i].address, ans[i].key);
            else
                printf("%05d %d %05d\n", ans[i].address, ans[i].key,ans[i+1].address);
        }   
    }
    return 0;
}