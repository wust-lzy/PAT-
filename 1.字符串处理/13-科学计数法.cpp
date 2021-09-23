#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s[0]=='-')
        cout << "-";
    s = s.substr(1);
    int k = s.find("E");
    int t = stoi(s.substr(k + 1));
    if(t<0){//小数点向左移
        t = abs(t);
        s = "0." + string(t - 1, '0') +s[0]+ s.substr(2, k - 2);
    }
    else{
        
        if(t>=k-2){//需要补0的情况
            s = s[0] + s.substr(2, k - 2) + string(t - k + 2, '0');
        }
        else//不用补0
            s = s[0] + s.substr(2, t) +"."+ s.substr(t + 2, k - t - 2);
    }
    cout << s;
    return 0;
}