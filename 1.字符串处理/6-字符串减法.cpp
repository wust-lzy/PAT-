#include <iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N = 100010;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    unordered_map<char, int> cnt;
    for(char&c:s2)
        cnt[c]++;
    for(auto&c:s1){
        if(cnt.count(c))
            continue;
        else
            cout << c;
    }
    return 0;
}