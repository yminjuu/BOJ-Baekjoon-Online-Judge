#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

deque<int> wheel[4];
int rel[4][4];
int visited[4];

// 톱니의 동작: 시계방향(1)으로 돌면 8번에 있던 톱니가 1번으로 간다
        // 반시계방향(-1)으로 돌면 1번에 있던 톱니가 8번으로 간다
void rotate(int idx, int direction){
    if (direction==1){
        wheel[idx].push_front(wheel[idx].back());
        wheel[idx].pop_back();
    } else {
         wheel[idx].push_back(wheel[idx].front());
        wheel[idx].pop_front();
    }
}

void rotateBfs(int startIdx, int direction){
    queue<pair<int,int>> rq; // 회전 예정 저장
    queue<pair<int,int>> q; // 톱니 인덱스와 방향 저장
    
    rq.push({startIdx, direction});
    q.push({startIdx, direction});
    fill(&visited[0], &visited[3]+1, 0);

    visited[startIdx]= 1;

    while (!q.empty()){
        startIdx= q.front().first;
        direction= q.front().second;
        q.pop();
        
        int newDirection = direction == -1 ? 1 : -1; 
        
        for (int i=0; i<4; i++){
            
            if (rel[startIdx][i]==1 && !visited[i]){
                visited[i]= 1;
                
                if (i> startIdx) {
                    // 현재 톱니 기준 오른쪽 2 -> 6
                    if (wheel[startIdx][2] == wheel[i][6]) continue;
                } else {
                     // 현재 톱니 기준 왼쪽 7 -> 3
                    if (wheel[startIdx][6] == wheel[i][2]) continue;
                }
                q.push({i, newDirection});
                rq.push({i, newDirection});
                }
            }   
    }

    while (!rq.empty()){
        startIdx= rq.front().first;
        direction= rq.front().second;
        rq.pop();
        rotate(startIdx, direction);
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    rel[0][1] = 1;
    rel[1][0]= 1;
    rel[1][2]= 1;
    rel[2][1]= 1;
    rel[2][3]=1;
    rel[3][2]=1;
   
   for (int i=0; i<4; i++){
       char c;
       for (int j=0; j<8; j++){
           cin >> c;
           int tmp = c=='0' ? 0 : 1;
           wheel[i].push_back(tmp);
       }
   }

    int t;
    cin >> t;
    while (t--){
        int a,b;
        cin >> a >> b;
        rotateBfs(a-1,b);
    }

    int ans= 0;
    for (int i=0; i<4; i++){
        if (wheel[i][0]==1){
            ans+= (int)pow(2, i);
        }
    }

    cout << ans;

   return 0;
}
