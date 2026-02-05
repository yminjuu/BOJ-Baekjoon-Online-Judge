#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
using ll = long long;
typedef pair<ll,int> p;

vector<vector<p>> vec;
vector<ll> currMin;
vector<int> reached; // 도달 횟수를 센다. K번 도달까지만 큐에서 확인
vector<ll> ans;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int n,m,k;
   cin >> n >> m >> k;

    vec.resize(n+1); reached.resize(n+1); ans.resize(n+1);
    currMin.resize(n+1);
    fill(currMin.begin(), currMin.end(), LLONG_MIN);

    int a,b,c;
    while (m--){
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
    }

    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, 1}); 

    while (!pq.empty()){
        p currN = pq.top(); pq.pop();
        if (++reached[currN.second]<=k){
            for (int i=0; i<vec[currN.second].size(); i++){
                p nextN= vec[currN.second][i];

            // 확실하게 클 때에만 넣는다 (같을 수도 있음))
                if (currMin[nextN.first] < currN.first + nextN.second){
                    pq.push({currN.first + nextN.second, nextN.first});
                }
            }
        }
        if (reached[currN.second]==k) ans[currN.second] = currN.first;
    }

    for (int i=1; i<=n; i++){
        if (reached[i]>=k) cout << ans[i] << "\n";
        else cout << -1 << "\n";
    }

   return 0;
}
