#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, L, R;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};

int population[52][52];
int moveCnt=0; // 인구 이동 횟수

int visited[52][52]; // 방문 여부

bool bfs(int x, int y){
    queue<pair<int,int>> graph; // bfs 용
    vector<pair<int,int>> coo; // 연합을 이루는 도시들을 저장
    
    long total= population[x][y]; // 총 인구수를 저장
    visited[x][y]= 1; // 방문 여부
    
    coo.push_back({x,y});
    graph.push({x,y});

    while (!graph.empty()){
        x = graph.front().first; y= graph.front().second;
        for (int i=0; i<4; i++) {
            int newX= x+dx[i]; int newY= y+dy[i];
            int popDiff= abs(population[x][y]-population[newX][newY]);
            if (newX>=1 && newX<=N && newY>=1 && newY<=N && !visited[newX][newY] && popDiff>=L && popDiff<=R){
                visited[newX][newY]= 1;
                coo.push_back({newX, newY});
                graph.push({newX, newY});
                total+= population[newX][newY];
            }
        }   
        graph.pop();
    }

    if (coo.size()==1) return false;

    long newTotal = total / coo.size();
    for (int i=0; i<coo.size(); i++){
        pair p = coo[i];
        population[p.first][p.second] = newTotal; // 인구 갱신
    }
    return true;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> N >> L >> R;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++){
            cin >> population[i][j];
        }
    }

    while (true){
        moveCnt++;

        // 초기화
        fill(&visited[0][0], &visited[51][51], 0);

        bool flag= false;
        // dfs로 국경선 열고 인구 이동
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                if (!visited[i][j] && bfs(i,j)) flag= true;
            }
        }

        // 인구 이동 (인구 이동이 발생했는지 여부를 return 값으로)
        if (!flag) break;
    }

    cout << moveCnt-1;

   return 0;
}
