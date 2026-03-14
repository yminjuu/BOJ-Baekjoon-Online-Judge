#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
#include <cstring>

using namespace std;
using ll = long long;
using p = pair<int,int>;

struct comp{
    bool operator() (p& a, p& b) const {
        return a.first > b.first;
    }
};

bool cmp(p& a, p&b){
    if (a.first==b.first) return a.second > b.second;
    else return a.first < b.first; // 비용 작아야 앞에
}

bool isDuplicate(p& a, p&b){
    return a.second == b.second;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    vector<p> edge[50002]; // 특정 헛간에서 다른 헛간 도달 최단 경로

    for (int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({c,b});
        edge[b].push_back({c,a});
    }

    for (int i=1; i<=N; i++){
        if (edge[i].empty()) continue;

        sort(edge[i].begin(), edge[i].end(), cmp); // 정렬부터 (이부분 확인)
        edge[i].erase(unique(edge[i].begin(), edge[i].end(), isDuplicate), edge[i].end());
        // 비용이 작은 unique한 걸로만 채운 후 지운다.
    }

    // 다익스트라
    priority_queue<p, vector<p>, comp> pq;
    pq.push({0,1});

    ll path[50002];
    fill(&path[0], &path[50001]+1, LLONG_MAX);
    path[1]= 0;

    while (!pq.empty()){
        auto [cost, curr]= pq.top(); pq.pop();

        // 만약 더 작은 경로로 이미 방문했다면 패스
        if (cost > path[curr]) continue;
        path[curr]= cost; // 갱신
        
        // 여기서 방문할 수 있는 가까운 정점을 pq에 넣음
        for (int i=0; i<edge[curr].size(); i++) {
            auto [nextCost, next] = edge[curr][i];
            
            if (path[next] <= path[curr]+ nextCost) continue; 
            // 이미 더 작은 경로라면 패스

            pq.push({path[curr]+nextCost, next});
        }
    }

    cout << path[N];
    
   return 0;
}
