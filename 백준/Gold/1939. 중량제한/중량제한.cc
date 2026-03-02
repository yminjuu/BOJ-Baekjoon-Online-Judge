#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

using ll= long long;
int S,E;
using p = pair<ll,ll>;
vector<p> linked[100001]; 

bool bfs(ll limit){
    queue<int> q;
    int visited[100001];
    fill(&visited[0], &visited[100000]+1, 0);

    int st = S; q.push(st); visited[st]= 1;
    // 더이상 갈 수 잇는 경로가 없을 때까지
    while (!q.empty()){
        st = q.front(); q.pop();
        if (st==E) {
            return true;
        }
        
        for (int i=0; i<linked[st].size(); i++){
            ll nodenum = linked[st][i].first;
            ll currLimit= linked[st][i].second;

            if (visited[nodenum] || currLimit < limit) continue; // 해당 limit은 불가능한 경로
            else { visited[nodenum]=1; q.push(nodenum);}
        }
    }
    return false;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    while (M--){
        ll a,b,c;
        cin >> a>> b>> c;
        linked[a].push_back({b,c});
        linked[b].push_back({a,c});
    }

    cin >> S >> E;

    // 이분 탐색
    ll s= 1; ll e = 1000000000;
    ll ans = 0; // ans는 따로 저장해둠.
    while (s<=e){
        ll mid = (s+e)/2;

        bool isPossible = bfs(mid); // 단순히 해당 경로가 가능한지 물음

        if (isPossible) {
            s= mid+1;
            ans= mid;
        } else {
            e= mid-1; // mid를 제외하고 범위 줄임
        }
    }

    cout << ans;

   return 0;
}
