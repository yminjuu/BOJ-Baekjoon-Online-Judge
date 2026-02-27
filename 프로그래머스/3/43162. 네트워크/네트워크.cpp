#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int m,n;
vector<int> near[202];
int visited[202];

void bfs(int s){
    // s: 시작 노드
    queue<int> q;
    q.push(s);
    
    while (!q.empty()){
        s= q.front(); q.pop();
        
        for (int i=0; i<near[s].size(); i++){
            if (!visited[near[s][i]]){
                visited[near[s][i]]= 1;
                q.push(near[s][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    n= computers.size(); m= computers[0].size();
    int answer = 0;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++) {
            if (computers[i][j]) {
                // 인접 정보 저장
                near[i].push_back(j);
                near[j].push_back(i);
            }
        }
    }
    
    for (int i=0; i<n; i++){
            if (!visited[i]){
                visited[i]= 1;
                bfs(i);
                answer++;
            }
    }
 
    return answer;
}