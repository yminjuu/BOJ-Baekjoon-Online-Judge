#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using p = pair<string,string>;
using edge = pair<string, int>; // 공항명, 공항 인덱스

map<string, int> mp; // 공항과 공항의 인덱스 저장
vector<edge> paths[10001]; // 각 공항에서 도달 가능한 공항 정보 & 경로 저장
vector<p> edges; // 모든 에지 정보와 인덱스 관리

int visited[100000];
deque<int> deq; // 지나온 에지들의 인덱스를 저장
vector<string> answer;

// 현재 airportidx
void dfs(int airportIdx){
    if (deq.size()==edges.size()){
        // 모든 경로가 사용됐음.
        if (answer.size()==0){
            for (int i=0; i< edges.size(); i++){
            int d = deq.front(); deq.pop_front();
            answer.push_back(edges[d].first);
            if (i==edges.size()-1) answer.push_back(edges[d].second);
        }
        }
        return;
    }
    
    // 해당 공항에서 사용 가능한 모든 경로를 알파벳순으로 접근
    for (auto e : paths[airportIdx]){
        string name = e.first;
        int edgeIdx= e.second;
        
        // 사용한 경로라면 다시 사용 불가
        if (!visited[edgeIdx]) {
             // dfs 들어갈 때 deq에 해당 경로를 저장
            visited[edgeIdx]= 1;
            deq.push_back(edgeIdx);
            dfs(mp[name]);
            visited[edgeIdx]= 0;
            deq.pop_back();
        }
    }
    // 만약 모든 경로가 사용됐다면 answer 저장, 종료 후 return
}

    bool cmp (edge &a, edge &b){
        return a.first < b.first; // sort 함수 -> 정방향
    }

vector<string> solution(vector<vector<string>> tickets) {
    int idx=0; int airportIdx=1;
    
    for (auto v : tickets){
        string start = v[0];
        string end = v[1];
        
        if (mp[start]==0) mp[start]= airportIdx++;
        if (mp[end]==0) mp[end]= airportIdx++;
        
        edges.push_back({start, end}); // 에지 정보만 저장 (인덱스와 함께)
        paths[mp[start]].push_back({end, idx++}); // 해당 공항의 인접 리스트를 오름차순으로 저장
        
    }
    
    // 모든 공항에 대하여 paths를 알파벳 순 정렬
    
    for (int i=1; i<airportIdx; i++){
        sort(paths[i].begin(), paths[i].end(), cmp);
    }
    
    dfs(mp["ICN"]);
    
    return answer;
}