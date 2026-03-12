#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct Rate {
    int gold, silver, bronze;
};

struct cmp{
    bool operator() (const Rate& a, const Rate& b) const{
        if (a.gold==b.gold){
            if (a.silver==b.silver){
                return a.bronze > b.bronze;
            }
            else return a.silver > b.silver;
        } 
        else return a.gold > b.gold;
    }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, K;
    cin >> N >> K;

    map<Rate, int, cmp> rateMap;
    Rate ansRate;

    for (int i=1; i<=N; i++){
        int idx, g, s, b;
        cin >> idx >> g >> s >> b;
        rateMap[{g,s,b}]++;

        if (idx==K) ansRate = {g,s,b};
    }

    long long rate = 0;
    for (auto& [key, value] : rateMap){
        auto [g,s,b]= key;

        if ((g==ansRate.gold && s==ansRate.silver) && (b==ansRate.bronze)){
            cout << rate + 1;
            break;
        }
        rate += value;
    }

   return 0;
}
