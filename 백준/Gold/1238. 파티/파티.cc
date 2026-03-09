#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define MAX 987654321

struct Road {
    int e, t;
    bool operator < (const Road& tmp) const {
        return t > tmp.t; // pq는 반대
    }
};

int N,M,X;
vector<Road> normal_adj[1002], reverse_adj[1002];

// dist: 배열 포인터
// adj : 포인터
void dijkstra(int s, int dist[], vector<Road> adj[]){
    fill(dist, dist+N+1, MAX);
    priority_queue<Road> pq;

    dist[s]=0;
    pq.push({s, 0});
    
    while (!pq.empty()){
        int e= pq.top().e; int time = pq.top().t;
        pq.pop();

        if (dist[e] < time) continue;

        // 방문하게 된 노드에서 연결된 노드
        for (auto& edge: adj[e]){
            int next = edge.e;
            int nextT =edge.t;

            // 유의미한 경로일 때에만 pq에 넣는다.
            if (dist[next] > dist[e]+nextT){
                dist[next]= dist[e]+nextT;
                pq.push({next, dist[e]+nextT});
            }
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M >> X;

    // 인접 리스트 생성
    while (M--){
        int s, e, t;
        cin >> s >> e >> t;
        normal_adj[s].push_back({e,t});
        reverse_adj[e].push_back({s,t});
    }

    int costs[N+1];
    int dist[N+1];

    // 정방향 (X-> i) 구함
    dijkstra(X, dist, normal_adj);
    for (int i=1; i<=N; i++) costs[i]= dist[i];
    
    // 역방향을 통해 모든 (i->X) 구함
    dijkstra(X, dist, reverse_adj);

    int mx=0;
    for (int i=1; i<=N; i++) {
        costs[i]+= dist[i];
        mx= max(costs[i], mx);
    }

    cout << mx;

   return 0;
}
