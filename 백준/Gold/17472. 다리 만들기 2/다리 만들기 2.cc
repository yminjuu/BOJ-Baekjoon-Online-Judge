#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
using p= pair<int,int>;
typedef struct Edge {
    int s, e, v;
    bool operator > (const Edge &temp) const {
        return v > temp.v;
    }
} Edge;

// 상하좌우 판별용
int dr[]= {0,-1,0,1};
int dc[]= {1, 0,-1,0};
int arr[12][12]= {0,};
int visited[12][12]= {0,};

int parent[7]; // 각 섬 집합 표현
int N,M;

vector<p> island;
vector<vector<p>> islands;

int find(int a){
    if (parent[a]==a) return a;
    else return parent[a]= find(parent[a]);
}

void unionFunc(int a, int b){
    int pA= find(a); 
    int pB= find(b);

    if (pA!=pB) parent[pB]= pA;
}

void BFS(int x, int y, int cnt){
    queue<p> q; island.clear();
    q.push({x,y}); island.push_back({x,y});
    visited[x][y]= 1; arr[x][y]= cnt;

    while (!q.empty()){
        x= q.front().first; y= q.front().second; q.pop();
            for (int i=0; i<4; i++){
                if (arr[x+dr[i]][y+dc[i]] && !visited[x+dr[i]][y+dc[i]]){
                    // 접근 가능하다면 거기도 섬 영역
                    arr[x+dr[i]][y+dc[i]]= cnt;
                    visited[x+dr[i]][y+dc[i]]= 1;
                    q.push({x+dr[i], y+dc[i]});
                    island.push_back({x+dr[i], y+dc[i]});
                }
        }   
    }

    islands.push_back(island);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i=1; i<=N; i++){
        parent[i]= i;
        for (int j=1; j<=M; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            visited[i][j]=0;
        }
    }

    // 섬 찾기 로직
    int islandCnt=0;
    for (int i=1; i<=N ;i++){
        for (int j=1; j<=M; j++){
            if (arr[i][j] && !visited[i][j]) {
                BFS(i, j, ++islandCnt);
            }
        }
    }

    // 다리 찾기 로직
    for (int i=0; i<islands.size(); i++){
        // 모든 섬에 대하여
        for (int j=0; j<islands[i].size(); j++){
            // 모든 땅에 대하여
            int r = islands[i][j].first; int c= islands[i][j].second;
                
            // 4가지 방향에 대하여
            for (int k=0; k<4; k++){
                int tmpR = r+ dr[k]; int tmpC = c+dc[k];
                if (tmpR>=1 && tmpR<=N && tmpC>=1 && tmpC<=M && !arr[tmpR][tmpC]) {
                    int newR= tmpR; int newC = tmpC; int lth=1;
                    
                    while (true){
                        newR+= dr[k]; newC+= dc[k];
                        if (newR>=1 && newR<=N && newC>=1 && newC<=M && arr[newR][newC]==0){
                            // 다리 연장
                            lth++;
                            continue;
                        }
                        if (arr[newR][newC] && arr[newR][newC]!=arr[r][c]) {
                            // 새로운 섬이라면 종료
                            if (lth>=2){ 
                                pq.push({
                                    s: arr[r][c],
                                    e: arr[newR][newC],
                                    v: lth
                                });
                            }
                            break;
                        }
                        else { break; }
                    }
                }
                // 땅의 테두리가 아니고 
                // 값이 0이며 (바다이며)
                // 시작점을 결정
                // 새로운 섬이 나올 때까지 반복문을 돎
                
            }
        }
    }

    int ans=0; int edgeCnt=0;
    // 최소 신장 트리 구하기 로직
    while (!pq.empty()){
        Edge edge = pq.top(); pq.pop();
        if (find(edge.s)!=find(edge.e)){
            unionFunc(edge.s, edge.e);
            ans+=edge.v;
            edgeCnt++;
        }
    }

    if (edgeCnt!=islands.size()-1) cout << -1;
    else cout << ans;
    
   return 0;
}
