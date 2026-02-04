#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<vector<pair<int,int>>> vec; // 정방향 그래프
vector<vector<pair<int,int>>> reverseVec; // 역방향 그래프
vector<int> indegree; // 진입 차수 (정방향 기준)
vector<int> visited; // 임계 경로에 포함되는지 여부

int startN, endN;

queue<int> q;
vector<int> times; // 최대 걸린 시간

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;
    vec.resize(N+1);
    reverseVec.resize(N+1);
    indegree.resize(N+1);
    visited.resize(N+1);
    times.resize(N+1);

    while (M--){
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v,w});
        reverseVec[v].push_back({u,w});
        indegree[v]++;
    }
    cin >> startN >> endN;

    // 정방향 위상 정렬 -> 최댓값 구하기
    
    // start부터 시작
    q.push(startN);

    while (!q.empty()){
        int node = q.front(); q.pop();
        for (auto p: vec[node]) {
            int idx= p.first; int time= p.second;
            indegree[idx]--;
            
            times[idx] = max(times[idx], times[node]+time);

            if (indegree[idx]==0) q.push(idx);
        }
    }

    int ans=0;
    // 역방향 위상 정렬
    q.push(endN); visited[endN]= 1;
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (auto p: reverseVec[node]){
            int idx= p.first; int time= p.second;
            
            if (times[idx]+time == times[node]){
                if (!visited[idx]){
                    // 방문하지 않았을 때에만 큐에 삽입
                    q.push(idx);
                    visited[idx]= 1;
                }
                ans++;
                // 여러 개 있을 수 있으므로 break 하진 않음
            }
        }
    }

    cout << times[endN] << "\n" << ans;

   return 0;
}
