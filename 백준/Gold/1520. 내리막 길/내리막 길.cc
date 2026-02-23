#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N, M; 
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1, 0,0};
int height[502][502];
int dp[502][502]; // dp[i][j] => (i,j)에서 (M,N)까지 가는 방법 개수
int visited[502][502];

int dfs(int x, int y){
    if (x==M && y==N) return 1;
    if (dp[x][y]!=-1) return dp[x][y];
    
    visited[x][y] = 1;
    int cnt= 0;

    for (int i=0; i<4; i++){
        int newX= x+dx[i]; int newY= y+dy[i];
        if (newX>=1 && newX<=M && newY>=1 && newY<=N && !visited[newX][newY] && height[newX][newY]<height[x][y]){
            cnt += dfs(newX, newY);
        }
    }

    visited[x][y] = 0;
    dp[x][y]= cnt;
    return cnt;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> M >> N;

    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            cin >> height[i][j];
            dp[i][j]= -1;
        }
    }

    cout << dfs(1,1);

   return 0;
}
