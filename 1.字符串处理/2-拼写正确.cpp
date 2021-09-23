#include <iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N = 100010;

int main()
{
    string m[10] = {"zero",
                    "one",
                    "two",
                    "three",
                    "four",
                    "five",
                    "six",
                    "seven",
                    "eight",
                    "nine"};
    string n;
    cin >> n;
    int ans = 0;
    for(char &e:n)
        ans += e - '0';
    string t = to_string(ans);
    for (int i = 0; i < t.size();i++)
    {
        cout << m[t[i]-'0'];
        if(i!=t.size()-1)
            cout << " ";
    }
    return 0;
}