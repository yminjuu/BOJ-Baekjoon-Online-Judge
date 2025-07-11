#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, centerX, centerY, minCost=3000;

int dx[5]= {0, -1,1,0,0};
int dy[5]= {0, 0,0,-1,1};

bool isVisited[10][10]= {false};

int flowerBed[10][10];

void toggleVisited(int centerX, int centerY){
    for (int k=0; k<5; k++){
        int tmpX= centerX+dx[k]; int tmpY= centerY+dy[k];
        isVisited[tmpX][tmpY]= !isVisited[tmpX][tmpY];
    }
}

int getCost(int centerX, int centerY){
    int sum=0;
    for (int k=0; k<5; k++){
        int tmpX= centerX+dx[k]; int tmpY= centerY+dy[k];
        sum+= flowerBed[tmpX][tmpY];
    }
    return sum;
}

bool canPlace(int centerX, int centerY){
    // 방향 배열 사용해서 가능한지 확인
    for (int k=0; k<5; k++){
        int tmpX = centerX+dx[k]; int tmpY= centerY+dy[k];
        if (isVisited[tmpX][tmpY]) return false;
    }
    return true; // 정상적으로 반복문 끝났다면    
}

void findPos(int index, int cost){
    if (index==3){
        if (cost<minCost) minCost= cost;
        else return;
    } 

    for (int i=1; i<N-1; i++){
        // i : x 좌표
        for (int j=1; j<N-1; j++){
            // j: y좌표
            int tmpCost=0;
            if (canPlace(i,j)) {
                int tmpCost= getCost(i,j);
                if (minCost>cost+tmpCost) { // 백트래킹
                    toggleVisited(i,j);
                    findPos(index+1, cost+tmpCost);
                    toggleVisited(i,j);
                }
            }
           
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N;

   for (int i=0; i<N; i++){
      for (int j=0; j<N; j++) cin >> flowerBed[i][j];
   }

   findPos(0, 0);

   cout << minCost;

   return 0;
}