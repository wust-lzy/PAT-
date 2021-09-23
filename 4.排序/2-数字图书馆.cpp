#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

struct Book
{
    string id, name, author;
    set<string> keywords;
    string publisher, year;
};
int n, m;
int main()
{
    cin >> n;
    vector<Book> books;
    while (n--)
    {
        string id, name, author;
        cin >> id;
        getchar();
        getline(cin, name);//名字
        getline(cin, author);//作者
        string line;
        getline(cin, line);//关键词
        stringstream ssin(line);
        string keyword;
        set<string> keywords;
        while(ssin>>keyword)
            keywords.insert(keyword);
        string publisher, year;
        getline(cin, publisher);//出版社
        cin >> year;    //年份
        books.push_back({id, name, author, keywords, publisher, year});
    }

    cin >> m;
    getchar();
    string line;
    while(m--)
    {
        getline(cin, line);
        cout << line << endl;
        string info = line.substr(3);   //给出的关键词
        char idx = line[0];
        vector<string> ans;
        if (idx == '1')
        {
            for(Book&b:books){
                if(b.name==info)
                    ans.push_back(b.id);
            }
        }
        else if(idx=='2'){
            for(auto&b:books)
                if(b.author==info)
                    ans.push_back(b.id);
        }
        else if(idx=='3'){
            for(auto&b:books)
                if(b.keywords.count(info))
                    ans.push_back(b.id);
        }
        else if(idx=='4')
            for(auto&b:books){
                if(b.publisher==info)
                    ans.push_back(b.id);
            }
        else{
            for(auto&b:books)
                if(b.year==info)
                    ans.push_back(b.id);
        }

        if(ans.empty()){
            puts("Not Found");
        }
        else{
            sort(ans.begin(), ans.end());
            for(string &e:ans)
                cout << e << endl;
        }
    }
    return 0;
}