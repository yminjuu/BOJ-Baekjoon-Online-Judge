#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

deque<int> wheel[4];
int visited[4];

void rotate(int idx, int direction){
    if (direction==1){
        wheel[idx].push_front(wheel[idx].back());
        wheel[idx].pop_back();
    } else {
         wheel[idx].push_back(wheel[idx].front());
        wheel[idx].pop_front();
    }
}

// side 0: 양쪽 확인, -1: 왼쪽 확인, 1: 오른쪽 확인
void rotateBfs(int num, int direction, int side){
    int nextDirection = direction == 1 ? -1 : 1;
    // 왼쪽 톱니바퀴 확인
     if ((side==0 || side == -1) && num-1 >=0 ){
         if (wheel[num-1][2]!=wheel[num][6]) rotateBfs(num-1, nextDirection, -1);
     } 

    // 오른쪽 톱니바퀴 확인
    if ((side==0 || side == 1) && num+1 <= 3) {
        if (wheel[num][2]!=wheel[num+1][6]) rotateBfs(num+1, nextDirection, 1);
    }

    rotate(num, direction); // 양쪽 모두 전파 후 rotate
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

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
        rotateBfs(a-1,b,0);
    }

    int ans= 0;
    for (int i=0; i<4; i++){
        if (wheel[i][0]==1){
            ans+= (1 << i);
        }
    }

    cout << ans;

   return 0;
}
