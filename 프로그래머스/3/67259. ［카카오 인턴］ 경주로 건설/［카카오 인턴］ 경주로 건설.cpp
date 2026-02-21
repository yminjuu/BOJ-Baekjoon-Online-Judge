#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> gBoard;
int N;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int dp[30][30][2];
int visited[30][30];
// 0: x가 변경됨
// 1: y가 변경됨

void dfs(int x, int y, int cost, int dir){
    dp[x][y][dir]= min(dp[x][y][dir], cost);
    
    if (x==N-1 && y==N-1) return;
    if (cost != dp[x][y][dir]) return; // 더이상 탐색하지 않음
    
    visited[x][y]= 1;
    for (int i=0; i<4; i++){
        int newX = x + dx[i]; int newY = y+ dy[i];
        if (newX>=0 && newY>=0 && newX<N && newY<N && gBoard[newX][newY]==0 && !visited[newX][newY]){
            // 갈 수 있는 경우
            
            int newDir = i<=1 ? 1 : 0;
            int addedCost = newDir==dir ? 100 : 600;
            dfs(newX, newY, cost+ addedCost, newDir);
        } 
    }
    visited[x][y]= 0;
}

int solution(vector<vector<int>> board) {
    gBoard= board;
    
    N= board.size();
    // 초기화
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            for (int k=0; k<2; k++){
                dp[i][j][k]= INT_MAX;
            }
        }
    }
    
    dfs(0,0,0,0); // 왼/오로 이동
    dfs(0,0,0,1); // 위/아래로 이동
    
    return min(dp[N-1][N-1][0], dp[N-1][N-1][1]);
}