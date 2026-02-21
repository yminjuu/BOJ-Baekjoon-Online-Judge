#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
using p= pair<int,int>;
int N, K;
int dp[500005];
priority_queue<p, vector<p>, greater<p>> pq;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> N >> K;
    for (int i=0; i<=500004; i++){
        dp[i]= INT_MAX;
    }

    pq.push({0, N});

    while (!pq.empty()){
        int cost = pq.top().first; int pos = pq.top().second;
        pq.pop();
        
        if (pos>=100005) continue;
        
        dp[pos]= min(dp[pos], cost);

        if (pos==K){
            cout << cost;
            return 0;
        }

        if (cost > dp[pos]) continue; // 최소가 아니었으면 종료

        if (dp[pos+1] > cost+1) {
            dp[pos+1]= cost+1;
            pq.push({cost+1, pos+1});
        }
        if (pos-1>=0 && dp[pos-1] > cost+1) {
            dp[pos-1]= cost+1;
            pq.push({cost+1, pos-1});
        }
        if (pos*2<=100000 && pos!=0 && dp[pos*2] > cost) {
            dp[pos*2]= cost;
            pq.push({cost, pos*2});
        }
    }

   return 0;
}
