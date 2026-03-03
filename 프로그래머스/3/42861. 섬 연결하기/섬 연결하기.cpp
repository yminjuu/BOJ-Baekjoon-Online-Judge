#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

long ans=0;
int visited[102]; 
int linked[102][102];
vector<int> nodes;

int solution(int n, vector<vector<int>> costs) {
    
    for (int i=0; i<costs.size(); i++){
        if (costs[i].size()==3){
            int s = costs[i][0];
            int e = costs[i][1];
            int cost = costs[i][2];

            linked[s][e]= cost;
            linked[e][s]= cost;   
        }
    }
    
    // 0번 노드에서 시작
    nodes.push_back(0); visited[0]= 1;
    
    while (nodes.size()<n){
        long minCost=  LLONG_MAX;
        int minIdx;
        // 현재 갈 수 있는 노드에 대해
        for (int i=0; i<nodes.size(); i++){
            int currNode= nodes[i]; // 현재 노드 번호
            // 모든 경로에 대하여
            for (int j=0; j<n; j++){
                if (linked[currNode][j]!=0 && !visited[j] && minCost > linked[currNode][j]){
                    // 아직 방문하지 않았다면
                    minCost = linked[currNode][j];
                    minIdx= j;
                }
            }
        }
        
        nodes.push_back(minIdx);
        visited[minIdx]= 1;
        ans+= minCost;
    }
    
    return ans;
}
