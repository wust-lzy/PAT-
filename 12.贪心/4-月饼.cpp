#include <bits/stdc++.h>
using namespace std;
struct cake
{
    double weight, price;
};
int main()
{
    int n;
    double d;
    cin >> n >> d;
    vector<cake> cakes(n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &cakes[i].weight);
    for (int i = 0; i < n; i++)
        scanf("%lf", &cakes[i].price);
    sort(cakes.begin(), cakes.end(),[](cake&a,cake&b){
         return a.price/a.weight > b.price/b.weight;
    });
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        if(cakes[i].weight<=d)
        {
            total += cakes[i].price;
            d -= cakes[i].weight;
        }
        else{
            total += d/cakes[i].weight *cakes[i].price;
            break;
        }
    }
    printf("%.2lf\n", total);
    return 0;
}
