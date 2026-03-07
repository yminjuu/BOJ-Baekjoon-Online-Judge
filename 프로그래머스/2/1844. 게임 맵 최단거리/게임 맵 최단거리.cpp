#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>

using namespace std;
using p = pair<int,int>;

vector<vector<int> > g_map;
int N,M;
int visited[102][102];
int ans[102][102]; // 이 좌표까지 가는 최솟값
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};

void bfs(int x, int y){
    queue<p> q;
    q.push({x,y});
    visited[x][y]= 1;
    ans[x][y]= 1;
    
    while (!q.empty()) {
        x= q.front().first;
        y= q.front().second;
        q.pop();
        
        for (int d=0; d<4; d++){
            int nextX= x+dx[d];
            int nextY= y+dy[d];
            if (nextX>=0 && nextY>=0 && nextX<N && nextY<M && !visited[nextX][nextY] && g_map[nextX][nextY]!=0){
                visited[nextX][nextY]= 1;
                q.push({nextX,nextY});
                ans[nextX][nextY]= ans[x][y]+1; // 이때만 최초 발견/ 최단 거리이므로 넣어줌
            }
        }
    }
}

// 0:벽, 1: 벽 없음
int solution(vector<vector<int> > maps)
{
    g_map= maps;
   N= maps.size(); M =maps[0].size();
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> maps[i][j];
        }
    }
    
    bfs(0,0);
    
    if (ans[N-1][M-1]==0) return -1;
    else return ans[N-1][M-1];
}