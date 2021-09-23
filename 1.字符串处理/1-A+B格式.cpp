#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    a += b;
    if(a<0)
    {
        cout << "-";
        a *= -1;
    }
    string ans = to_string(a);
    stack<char> s;
    int cnt = 0;
    for (int i = ans.size() - 1; i >= 0;i--)
    {
        cnt++;
        s.push(ans[i]);
        if(cnt%3==0)
            s.push(',');
    }
    if(s.top()==',')
        s.pop();
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}