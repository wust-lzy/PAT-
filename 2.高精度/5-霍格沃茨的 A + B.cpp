#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010;

int main()
{
    int a1, b1, c1, a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    c1 += c2;
    if(c1>28)
    {
        b1 += c1 / 29;
        c1 %= 29;
    }
    b1+= b2;
    if(b1>16)
    {
        a1 += b1 / 17;
        b1 %= 17;
    }
    a1 += a2;
    printf("%d.%d.%d", a1, b1, c1);
    return 0;
}