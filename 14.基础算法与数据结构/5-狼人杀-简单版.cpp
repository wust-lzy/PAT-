#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int n;
int talk[N];

bool islie(int k,int i,int j)//判断i和j是狼人的情况下，第k个人是否说谎
{
    int t = talk[k];
    if(t>0){//t是好人,说谎了
        return t == i || t == j;
    }else{//t是狼人
        t = -t;
        return !(t == i || t == j);
    }
        
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> talk[i];
    for (int i = 1; i <= n-1;i++){
        for (int j = i + 1; j <= n;j++){
            int s = islie(i, i, j) + islie(j, i, j);//两个狼人有一个说谎
            if(s!=1)
                continue;
            s = 0;
            for (int k = 1; k <= n;k++)
                s += islie(k, i, j);
            if(s==2)
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    puts("No Solution");
    return 0;
}