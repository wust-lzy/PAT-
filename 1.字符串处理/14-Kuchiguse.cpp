#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 110;
string strs[N];

int main()
{
    int n, minn = 300;
    cin >> n;
    getchar();
    for (int i = 0; i < n;i++)//取最小长度
    {
        getline(cin, strs[i]);
        minn = min(minn, (int)strs[i].length());
    }
    bool flag = false;
    while(!flag&&minn>0){//从最大到小枚举每个字符串是否相等
        bool t = true;
        string fir = strs[0].substr(strs[0].length() - minn);
        for (int i = 1; i < n;i++){
            if(fir!=strs[i].substr(strs[i].length()-minn)){
                t = false;
                break;
            }
        }
        flag = t;
        if(!flag)
            minn--;
    }
    // cout<<minn<<endl;
    if(minn==0)
        cout << "nai";
    else
        cout << strs[0].substr(strs[0].length() - minn);
    return 0;
}