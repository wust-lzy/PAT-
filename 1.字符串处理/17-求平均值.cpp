#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    double sum = 0;
    while(n--){
        string num;
        cin >> num;
        bool flag = 1;
        double x;
        try{
            size_t idx;
            x = stof(num, &idx);
            if(idx<num.size())
                flag = 0;
        }
        catch(...){
            flag = 0;
        }
        if(x<-1000||x>1000)
            flag = 0;
        int k = num.find(".");
        if(k!=-1&&num.size()-k>3)
            flag = 0;
        if(flag)
        {
            cnt++;
            sum += x;
        }
        else
            printf("ERROR: %s is not a legal number\n", num.c_str());
    }
    if(!cnt)
        puts("The average of 0 numbers is Undefined");
    else if(cnt==1)
        printf("The average of 1 number is %.2lf\n", sum);
    else
        printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
    return 0;
}