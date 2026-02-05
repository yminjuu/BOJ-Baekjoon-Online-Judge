#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
using ll = long long;
typedef pair<ll,int> p;
priority_queue<int> distQueue[1001];

vector<vector<p>> vec;
vector<ll> ans;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int n,m,k;
   cin >> n >> m >> k;

    vec.resize(n+1); ans.resize(n+1);

    int a,b,c;
    while (m--){
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
    }

    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, 1}); 

    while (!pq.empty()){
        p currN = pq.top(); pq.pop();
        if (distQueue[currN.second].size()>=k) continue;
        if (distQueue[currN.second].size()<k) distQueue[currN.second].push(currN.first); // 다음으로 작은값 넣음
        
        if (distQueue[currN.second].size()<=k){
            for (int i=0; i<vec[currN.second].size(); i++){
                p nextN= vec[currN.second][i];
                // 최솟값보다 작을 수도, 클수도 있음.
                
                // push 조건 추가 (이미 정답 결정됐으면 넣지 않음)
                if (distQueue[nextN.first].size()<k) pq.push({nextN.second + currN.first, nextN.first});
            }
        } 
    }

    for (int i=1; i<=n; i++){
        if (distQueue[i].size()==k) cout << distQueue[i].top() << "\n";
        else cout << -1 << "\n";
    }

   return 0;
}
