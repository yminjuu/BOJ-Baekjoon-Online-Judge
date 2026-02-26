#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using p = pair<int,int>;
#define MOD 1000000007

int isPuddle[102][102];
long path[102][102];
int dx[2]= {0, 1};
int dy[2]= {1, 0};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for (int i=0; i<puddles.size(); i++){
        int x = puddles[i][0]; int y= puddles[i][1];
        isPuddle[x][y]=1;
    }
    
    queue<p> q;
    path[1][1]= 1;
    q.push({1,1});
    
    // BFS 사용, 이미 최단경로 알면 더이상 진행하지 않음
    while (!q.empty()){
        int x= q.front().first; int y= q.front().second;
        q.pop();
        
        for (int i=0; i<2; i++){
            int newX= x+dx[i]; int newY = y+dy[i];
            if (newX>=1 && newX<=m && newY>=1 && newY<=n && !isPuddle[newX][newY]){
                if (path[newX][newY]==0) {
                    // 첫 방문일 때에만 넣는다
                    q.push({newX, newY});
                    path[newX][newY]= path[x][y];
                } else path[newX][newY]= (path[newX][newY]+ path[x][y]) % MOD;
            }
        }
    }
    
    answer = path[m][n] % MOD;
    return answer;
}