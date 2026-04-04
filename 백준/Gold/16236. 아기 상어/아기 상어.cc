#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

using namespace std;
using p = pair<int,int>;

#define x first
#define y second

int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    int N;
    cin >> N;

    int arr[N+2][N+2];
    vector<int> currPos(2, 0); // 사이즈 2, 0으로 초기화
    
    int sharkSize= 2;
    int time=0;
    int ateFishCnt=0;

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> arr[i][j];

            if (arr[i][j]==9) {
                currPos[0]= i;
                currPos[1]= j;
                arr[i][j]=0;
            }
        }
    }

    int visited[N+2][N+2]; fill(&visited[0][0], &visited[N+1][N+1]+1, 0);

    // "다음 이동 위치 찾기"를 반복하는 BFS 로직
    while (true){
        // BFS로 탐색
        queue<pair<p, int>> q;
        int nextCost=500;
        q.push({{currPos[0], currPos[1]}, 0});

        priority_queue<p, vector<p>, greater<p>> posCandidates; // 다음 위치 후보 (x작 -> y작)

        // 다음 이동 위치를 찾기 위한 BFS 로직
        while (!q.empty()){
            int currX= q.front().x.x; int currY= q.front().x.y;
            int currCost= q.front().y;
            q.pop();
            if (!posCandidates.empty() && nextCost <= currCost) break;
            // 이미 찾았고 더 비용 큰 경로 찾을 필요 없음

            for (int d=0; d<4; d++){
                int nextX= currX+dx[d]; int nextY= currY+dy[d];
                
                if (nextX>=1 && nextY>=1 && nextX<=N && nextY<=N && !visited[nextX][nextY] && arr[nextX][nextY]<=sharkSize){
                    visited[nextX][nextY]= 1;
                    
                    if (arr[nextX][nextY] && arr[nextX][nextY]<sharkSize) {
                        if (posCandidates.empty()) nextCost= currCost+1; // 현재 마지노선 비용 고정
                        posCandidates.push({nextX, nextY});
                    } else if (posCandidates.empty()){
                        q.push({{nextX, nextY}, currCost+1});
                    }
                }
            }
        }

        if (!posCandidates.empty()) {
            auto [nextX, nextY]= posCandidates.top();
            
            currPos[0]= nextX;
            currPos[1]= nextY;

            ateFishCnt++;
            arr[nextX][nextY]= 0; // 비움
            
            if (sharkSize == ateFishCnt) {
                ateFishCnt=0;
                sharkSize++;
            }

            while (!posCandidates.empty()) posCandidates.pop();
            fill(&visited[0][0], &visited[N+1][N+1]+1, 0);
            time+= nextCost;
        }

        // 못 찾았고 큐도 비었음
        else {
            cout << time;
            break;
        }
    }

   return 0;
}
