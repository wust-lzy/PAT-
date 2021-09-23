#include <bits/stdc++.h>
using namespace std;


int main()
{
    int x;
    cout << "#";
    for (int i = 0; i < 3;i++)
    {
        cin >> x;
        int a = x / 13;
        if(a>=10)
            cout << (a - 10) + 'A';
        else
            cout << a;
        a = x % 13;
        if(a>=10)
            cout << (a - 10) + 'A';
        else
            cout << a;
    }
        return 0;
}