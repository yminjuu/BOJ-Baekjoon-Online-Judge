#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int path[102][102];
int visited[102][102];

typedef struct X {
    int x, y;
} X;

// 1 => 이동 가능 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            char c;
            cin >> c;
            path[i][j]= c-'0';
        }
    }
    
    queue<pair<X, int>> q;
    q.push({{1,1}, 1});
    visited[1][1]= 1;

    //BFS
    while (!q.empty()){
        int x = q.front().first.x; int y= q.front().first.y;
        int cnt = q.front().second;
        q.pop();

        if (x==N && y==M) {
            cout << cnt;
            return 0;
        }

        for (int i=0; i<4; i++){
            int newX= x + dx[i];
            int newY= y+ dy[i];
            if (newX>=1 && newY>=1 && newX<=N && newY<=M && !visited[newX][newY] && path[newX][newY]){
                visited[newX][newY] = 1;
                q.push({{newX, newY}, cnt+1});
            }
        }
    }

   return 0;
}
