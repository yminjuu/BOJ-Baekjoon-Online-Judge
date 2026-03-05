#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
vector<int> edge[102]; // 인접 리스트
int arr[102][102]; // 선후 관계를 기록
// arr[i][j]에서 1이라면 i->j이고
// arr[i][j]에서 0이라면 j->i이다.
// -1로 초기화해준다.

int visited[102];

// 1 -> 2,3
// 3 -> 4
void bfs(int node){
    fill(&visited[0], &visited[101]+1, 0);
    
    queue<int> q;
    q.push(node);
    
    while (!q.empty()){ // 더이상 방문 가능한 엣지가 없을 때까지
        int currNode = q.front(); q.pop();
        visited[currNode]= 1;
        
        for (int i=0; i<edge[currNode].size(); i++){
            int nextNode = edge[currNode][i]; 
            
            if (!visited[nextNode]){
                q.push(nextNode);
                
                // 모든 이미 방문한 노드에 대해 선후 관계 기록
                for (int j=1; j<=N; j++){
                    if (arr[j][currNode]==1) {
                        // j-> currNode가 발견되면
                        // j-> nextNode의 선후관계를 기록해준다.
                        arr[j][nextNode]= 1; // j 다음에 nextnode가 온다
                        arr[nextNode][j]= 0; // nextnode는 j의 뒤에 있다.
                    }
                }
            }
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    N= n;
    int answer = 0;
    memset(arr, -1, sizeof(arr));
    
    for (int i=0; i<results.size(); i++){
        int a = results[i][0];
        int b = results[i][1];
        
        edge[a].push_back(b); // a->b의 선후관계를 기록
        arr[a][b]= 1;
        arr[b][a]= 0;
    }
    
    for (int i=1; i<=n; i++){
        bfs(i);
    }
    
    int ans =0;
    for (int i=1; i<=n; i++){
        bool b= true;
        for (int j=1; j<=n; j++) {
            cout << arr[i][j] << " ";
            if (i!=j && arr[i][j]==-1) {
                b= false;
            }
                // 결정되지 않았다면
        }
        if (b) ans++;
        cout << "\n";
    }
    return ans;
}

// (1) 플로이드 워셜
// (2) BFS / DFS 응용

// 1 -> 2 -> 3,4
// 4 -> 5 -> 6