#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Big {
     int h,w;
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;
    vector<Big> vec;

    for (int i=0; i<N; i++){
        int h,w;
        cin >> h >> w;
        vec.push_back({h,w});
    }

    for (int i=0; i<N; i++){
        auto [h,w]= vec[i];
        int cnt=0;
        for (int j=0; j<N; j++){
            auto [compH, compW]= vec[j];
            if (h < compH && w < compW) cnt++;
        }
        cout << cnt+1 << " ";
    }

   return 0;
}
