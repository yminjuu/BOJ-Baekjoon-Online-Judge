#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

#define x first
#define y second
using namespace std;
using p = pair<int,int>;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N,M,L,K;
    cin >> N >> M >> L >> K;

    vector<p> stars;
    for (int i=0; i<K; i++){
        int x,y;
        cin >> x >> y;
        stars.push_back({x,y});
    }

    int mx = 0;
    for (int i=0; i<stars.size(); i++){
        for (int j=0; j<stars.size(); j++){
            int x = stars[i].x;
            int y= stars[j].y;

            int cnt=0;
            for (int k=0; k<stars.size(); k++){
                auto [newX,newY] = stars[k];
                if (newX>=x && newX<=x+L && newY>=y && newY<=y+L) cnt++;
            }
            mx = max(cnt, mx);
        }
    }

    cout << stars.size() - mx;

   return 0;
}
