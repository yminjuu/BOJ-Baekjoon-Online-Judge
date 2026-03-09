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
vector<Road> path[1002];

int dijkstra(int s, int e){
    int minPath[N+1];
    fill(&minPath[0], &minPath[N]+1, MAX);
    priority_queue<Road> pq;

    pq.push({s, 0});
    while (!pq.empty()){
        int e= pq.top().e; int time = pq.top().t;
        pq.pop();

        // 제일 먼저 나온 최단경로일 때만
        if (minPath[e] > time){
            minPath[e]= time;

            // 방문하게 된 노드에서 연결된 노드
            for (int i=0; i<path[e].size(); i++){
                int next = path[e][i].e;
                int nextT =path[e][i].t;

                // 유의미한 경로일 때에만
                if (minPath[next] > minPath[e]+nextT){
                    pq.push({next, minPath[e]+nextT});
                }
            }
        }
    }

    return minPath[e];
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
        path[s].push_back({e,t});
    }

    // 모든 노드에서 다익스트라로 최단 왕복 경로 구해서 max 값과 비교
    int mx=0;
    for (int i=1; i<=N; i++){
        int cost=0;

        cost+= dijkstra(i, X);
        cost+= dijkstra(X,i);

        mx = max(mx, cost);
    }

    cout << mx;

   return 0;
}
