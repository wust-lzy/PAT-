#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010;

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    string g[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i = 0;
    for (i = 0; i < s1.length() && i < s2.length(); i++)
    {
        if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G')
        {
            cout << g[s1[i] - 'A'] << " ";
            break;
        }
    }
    i++;
    while (i < s1.length() &&i<s2.length()){
        if(s1[i]==s2[i]&&isdigit(s1[i])){
            printf("%02d:", s1[i] - '0');
            break;
        }
        else if(s1[i]==s2[i]&&s1[i]>='A'&&s2[i]<='N'){
            printf("%02d:", s1[i] - 'A' + 10);
            break;
        }
        i++;
    }
    for (i = 0; i < s3.length() && i < s4.length();i++)
    {
        if(s3[i]==s4[i]&&isalpha(s3[i])){
            printf("%02d", i);
            break;
        }
    }
        return 0;
}