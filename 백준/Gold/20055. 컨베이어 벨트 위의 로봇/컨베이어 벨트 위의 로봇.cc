#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <deque>

using namespace std;

int N, K;
int stage=0;
int zeroSpace=0 ;
int durability[202]; // i번 벨트의 내구성
deque<int> belts; // 컨베이어 벨트의 위치별 벨트 번호
deque<int> hasRobots; // 컨베이어 벨트의 위치별 로봇 존재 여부

// 벨트 & 로봇 회전 함수 (1)
void rotate(){
   belts.push_front(belts.back());
   belts.pop_back();

    hasRobots.push_front(hasRobots.back());
    hasRobots.pop_back();

    // 회전시 N-1번에 로봇 있다면 내림
    if (hasRobots[N-1]==1){
        hasRobots[N-1]= 0;
    }
}

// 로봇 이동 : 가장 먼저 벨트에 올라간 로봇부터 (2)
void robotMove(){
   for (int i=N-2; i>=0; i--){
       if (!hasRobots[i] || hasRobots[i+1] || !durability[belts[i+1]]) continue;

       // 로봇 내림
       hasRobots[i]=0;
       // 로봇 올림
       hasRobots[i+1]=1;
       durability[belts[i+1]]--;

       if (durability[belts[i+1]]==0) zeroSpace++;

       // 다음이 N번이라면 내림
       if (i+1 == N-1) hasRobots[N-1]=0;
   }
}

// 새로운 로봇 올리기
void addRobot(){
  if (durability[belts[0]]>0) {
      durability[belts[0]]--;
      hasRobots[0]= 1;

      if (durability[belts[0]]==0) zeroSpace++;
  }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> N >> K;
    
    for (int i=1; i<=2*N; i++){
        cin >> durability[i];
        belts.push_back(i);
        hasRobots.push_back(0);
    }

    while (true){
        stage++;
        // 벨트 회전
        rotate();

        // 로봇 이동 
        robotMove(); // N

        // 로봇 올리기 
        addRobot();

        // 내구도 확인 및 종료
        if (zeroSpace>=K) break;
    }

    cout << stage;
    
   return 0;
}
