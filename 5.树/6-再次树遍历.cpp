#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int N = 35;
int n, cnt,idx;
int pre[N], in[N], post[N];
void to_post(int root,int st,int ed)
{
    if(st>ed)
        return;
    int k = st;
    while(k<n&&pre[root]!=in[k])
        k++;
    to_post(root + 1, st, k - 1);
    to_post(root + (k - st)+1,k+1, ed);
    post[cnt++] = pre[root];
}
stack<int> stk;
int main()
{
    cin >> n;
    string s;
    int x;
    for (int i = 0; i < 2 * n; i++)//根据输入，构造前序和中序
    {
        cin >> s;
        if(s=="Push"){
            cin >> x;
            pre[cnt++] = x;
            stk.push(x);
        }else{
            in[idx++] = stk.top();
            stk.pop();
        }
    }
    cnt = 0;
    to_post(0, 0, n - 1);
    for (int i = 0; i < n;i++){
        cout << post[i];
        if(i!=n-1)
            cout << " ";
    }
        return 0;
}