#include <bits/stdc++.h>
using namespace std;
//个位上的数的单词
string a[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
//个位及以上的数的单词
string b[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int get(string word)//将单词转换为对应的数字
{
    for (int i = 0; i < 13;i++)
        if(a[i]==word)
            return i;
    for (int i = 0; i < 12;i++)
        if(b[i]==word)
            return (i + 1) * 13;
}

int main()
{
    int t;
    cin >> t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin, s);
        if(s[0]<='9')//数字转单词
        {
            int x = 0;
            for(char&c:s)
                x = x * 10 + c - '0';
            // cout << x << " ";
            if (x < 13)
                cout << a[x] << endl;
            else
            {
                cout << b[x/ 13-1];
                if(x%13==0)
                    cout << endl;
                else
                    cout<<" " << a[x % 13] << endl;
            }
        }
        else{//单词转数字
            int ans = 0;
            vector<string> words;
            int i = 0, j = 0;
            while(j<s.length())//将带有空格的单词转化为单独的单词
            {
                if(s[j]==' ')
                {
                    words.push_back(s.substr(i, j - i));
                    i = j + 1;
                }
                j++;
            }
            words.push_back(s.substr(i));
            for(string &word:words)
                cout << word << " ";
            for (string &word : words)
                ans += get(word);
            cout << ans << endl;
        }
    }
    return 0;
}