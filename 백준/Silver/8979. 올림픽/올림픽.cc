#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct Rate {
    int g,s,b;
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, K;
    cin >> N >> K;

    vector<Rate> vec(N+2);
    for (int i=1; i<=N; i++){
        int idx, g, s, b;
        cin >> idx >> g >> s >> b;
        vec[idx] = {g,s,b};
    }

    // K보다 큰 국가의 개수를 count한다
    long long rate = 0;
    for (int i=1; i<=N; i++){
        auto [g,s,b]= vec[i];
        if (g==vec[K].g){
            if (s==vec[K].s){
                if (b>vec[K].b) rate++;
            } else if (s>vec[K].s) rate++;
        } else if (g > vec[K].g) rate++;
    }

    cout << rate + 1;
   
   return 0;
}
