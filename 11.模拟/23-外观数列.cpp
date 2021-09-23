#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string d;
    cin >> d >> n;
    for (int cnt = 1; cnt < n;cnt++)
    {
        string next;
        for (int i = 0; i < d.length();)
        {
            int j = i+1;
            while (d[j]==d[i])
                j++;
            next +=d[i]+to_string(j - i);
            i = j;
        }
        d = next;
    }
    cout << d;
    return 0;
}