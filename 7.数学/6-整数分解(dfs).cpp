#include <bits/stdc++.h>
using namespace std;

vector<int> factors;
int n, k, p;
int max_sum = -1;
vector<int> ans, path;
int quick_pow(int a, int b)
{
    int ans = 1;
    while(b){
        if(b&1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
void dfs(int idx,int sum,int facsum){
    if(path.size()>k||sum>n||idx<0)
        return;
    if(path.size()==k&&sum==n){
        if(facsum>max_sum){
            max_sum = facsum;
            ans = path;
        }
        return;
    }
    
    path.push_back(factors[idx]);
    dfs(idx, sum + quick_pow(factors[idx], p), facsum + factors[idx]);//选了
    path.pop_back();//不选
    dfs(idx-1, sum, facsum);
}
int main()
{
    cin >> n >> k >> p;
    for (int i = 1; quick_pow(i,p) <= n; i++){
        factors.push_back(i);
    }
    dfs(factors.size()-1,0, 0);
    if(max_sum==-1)
        puts("Impossible");
    else{
        printf("%d = ", n);
        for (int i = 0; i < ans.size();i++){
            printf("%d^%d", ans[i], p);
            if(i!=ans.size()-1)
                printf(" + ");
        }
    }
    return 0;
}