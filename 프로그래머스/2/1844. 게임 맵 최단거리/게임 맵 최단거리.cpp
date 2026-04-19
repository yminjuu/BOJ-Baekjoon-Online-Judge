#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;
vector<vector<int> > gmaps;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int N,M;

using p = pair<int,int>;

int bfs(){
    queue<p> q;
    q.push({0,0});
    int path[102][102];
    fill(&path[0][0], &path[101][101]+1, 0);
    
    path[0][0]= 1;
    while (!q.empty()){
        auto [x,y]= q.front(); q.pop();
        
        for (int d=0; d<4; d++){
            int newX = x+dx[d]; int newY= y+dy[d];
            if (newX>=0 && newY>=0 && newX<N && newY<M && gmaps[newX][newY] && !path[newX][newY]) {
                path[newX][newY]= path[x][y]+1;
                q.push({newX, newY});
            }
        }
    }
    
    return path[N-1][M-1];
}

// 0:벽, 1: 벽 없음
int solution(vector<vector<int> > maps)
{
    gmaps= maps;
    N = maps.size(); M = maps[0].size();
    
    int ans = bfs();
    if (ans==0) ans= -1;
    return ans;
}