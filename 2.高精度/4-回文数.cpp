#include <bits/stdc++.h>
using namespace std;

string add(string &a,string &b)//大数加法
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int n = a.length(), m = b.length();
    string ans;
    int t=0;
    for (int i = 0; i < n||i<m;i++)
    {
        if(i<n)
            t+=a[i]-'0';
        if(i<m)
            t+=b[i]-'0';
        ans+=t%10+'0';
        t/=10;
    }
    if(t)
        ans+=t+'0';
    reverse(ans.begin(),ans.end());
    return ans;
}
bool check(string &s)   //判断回文串
{
    int n=s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
int main()
{
    string a;
    int k;
    cin>>a>>k;
    for(int i=0;i<k;i++)
    {
        if(check(a))
        {
            cout<<a<<endl<<i;
            return 0;
        }
        string temp=a;
        reverse(a.begin(),a.end());//和回文串相加
        a=add(a,temp);
    }
    cout<<a<<endl<<k;
    return 0;
}