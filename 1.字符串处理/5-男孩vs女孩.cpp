#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 100010;

int main()
{
    string boy, girl, boy_id, girl_id;
    string name, gender, id;
    int score,boy_score=101,girl_score=-1;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> name >> gender >> id >> score;
        if(gender=="M")
        {
            if(score<boy_score){
                boy_score = score;
                boy = name;
                boy_id = id;
            }
        }
        else if(gender=="F")
        {
            if(score>girl_score){
                girl_score = score;
                girl = name;
                girl_id = id;
            }
        }
    }
    bool flag = true;
    if(girl_score==-1)
    {
        flag = false;
        puts("Absent");
    }else{
        cout << girl << " " << girl_id << endl;
    }

    if(boy_score==101){
        flag = false;
        puts("Absent");
    }else{
        cout << boy << " " << boy_id << endl;
    }
    if(!flag){
        puts("NA");
    }
    else
        cout << girl_score - boy_score;
    return 0;
}