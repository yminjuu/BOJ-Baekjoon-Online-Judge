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
vector<ll> dis;
vector<int> visited;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;
    vec.resize(N+1);
    dis.resize(N+1);
    visited.resize(N+1);

    int n, v, w;
    while (M--){
        cin >> n >> v >> w;
        vec[n].push_back({v,w});
    }

    int startN, endN;
    cin >> startN >> endN;
    fill(dis.begin(), dis.end(), LLONG_MAX);
    dis[startN]=0;

    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, startN});

    while (!pq.empty()){
        p currN = pq.top(); pq.pop();
        if (visited[currN.second]) continue; // 큐에 넣지 않음
        visited[currN.second] = 1;
        
        for (int i=0; i<vec[currN.second].size(); i++){
            p nextN = vec[currN.second][i];
            if (dis[nextN.first] > dis[currN.second] + nextN.second){
                dis[nextN.first] = dis[currN.second] + nextN.second;
                pq.push({dis[nextN.first], nextN.first});
            }
        }
    }

    cout << dis[endN];

   return 0;
}
