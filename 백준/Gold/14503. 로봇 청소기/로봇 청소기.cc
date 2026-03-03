#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N, M; 
int x,y,dir;
int arr[52][52]; // -1: 청소됨, 0: 청소되지 않음, 1: 벽, 

// 현재 dir에 따라 다음 좌표를 안내
int dy[4] = {0, 1, 0, -1};
int dx[4]= {-1, 0, 1, 0};

int back[4]= {2,3,0,1};
// 후진 확인
// 0 -> 2
// 1 -> 3
// 2 -> 0
// 3 -> 1

long ans =0; // 청소하는 칸 개수

void clean(int currX, int currY){
    if (arr[currX][currY]==0) {
        arr[currX][currY]= -1;
        ans++;
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M; // 방 크기
    cin >> x >> y >> dir;
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    while (true){
        // 1. 현재 칸 확인 -> 청소
        clean(x,y);

        // 2-1. 주변 4칸 중 청소되지 않은 빈칸이 없음
        bool isClean= true;
        for (int d=0; d<4; d++){
            int nextX= x+ dx[d];
            int nextY= y+ dy[d];
            if (arr[nextX][nextY]==0) isClean= false; // 청소되지 않은 칸 있음
        }

        if (isClean) {
              // 2-1-1. 방향 유지, 후진 가능하면 후진
            int backDir = back[dir];
            int nextX= x+dx[backDir]; int nextY= y+dy[backDir];

            if (arr[nextX][nextY]==1) break;
            // 2-1-2. 뒤쪽이 벽이라 후진할 수 없음 -> break  
            else {
                x= nextX;
                y= nextY;
            }
        }

        // 2-2. 주변 4칸 중 청소되지 않은 빈칸이 있음
            else {
                dir -= 1;
                // 2-2-1. 90% 반시계 회전 (dir-1) 후 -1이라면 3으로 이동
                if (dir==-1) dir= 3;

                int nextX= x+dx[dir];
                int nextY= y+dy[dir];

                // 앞쪽 칸이 청소되지 않았따면 한 칸 전진
                if (arr[nextX][nextY]==0) {
                    x= nextX;
                    y= nextY;
                }
            }
    }

    cout << ans;

   return 0;
}
