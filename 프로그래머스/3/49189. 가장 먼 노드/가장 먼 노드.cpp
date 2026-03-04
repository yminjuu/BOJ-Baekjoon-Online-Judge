#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

vector<int> edgeEach[20001];
int minPath[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    // 에지 정보 저장
    for (int i=0; i<edge.size(); i++){
        int a= edge[i][0]; int b= edge[i][1];
        edgeEach[a].push_back(b);
        edgeEach[b].push_back(a);
    }
    
    // 특정 노드에서 가장 먼 노드 
    // 가중치 1
    // 양방향 간선
    queue<int> q;
    q.push(1); 
    
    fill(&minPath[0], &minPath[n]+1, INT_MAX);
    int mx = 0; minPath[1]= 0;
    
    while (!q.empty()){
        int currNode= q.front(); q.pop();
        
        for (int i=0; i<edgeEach[currNode].size(); i++){
            int nextNode = edgeEach[currNode][i];
            
            if (minPath[nextNode]==INT_MAX){
                // BFS이므로 이때가 최소
                minPath[nextNode]= minPath[currNode]+1;
                q.push(nextNode);
                mx = minPath[nextNode];
            }
        }
    }
    
    for (int i=2; i<=n; i++){
        if (minPath[i]==mx) answer++;
    }
    
    return answer;
}