#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
struct node{
    int address, next;
    char data;
    bool flag;
}nodes[N];
int ad1, ad2, n;
int main()
{
    cin >> ad1 >> ad2 >> n;
    for (int i = 0; i < n;i++){
        int ad, ne;
        char c;
        cin >> ad >> c >> ne;
        nodes[ad] = {ad, ne, c, 0};
    }
    for (int i = ad1; i != -1;i=nodes[i].next)
        nodes[i].flag = 1;
    for (int i = ad2; i != -1;i=nodes[i].next){
        if(nodes[i].flag){
            printf("%05d", nodes[i].address);
            return 0;
        }
    }
    puts("-1");
    return 0;
}