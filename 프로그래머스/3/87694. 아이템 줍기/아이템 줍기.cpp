#include <string>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int field[102][102];
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
int inverse[4] = {1, 0, 3, 2};

int initialsX, initialsY, initialeX, initialeY;
int ans = INT_MAX;

void print(){
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
}

// dIdx: direction index
void find(int dIdx){
    int cost= 0;
    int sX= initialsX;
    int sY= initialsY;
    
    // 한쪽 방향으로만 움직이다가 해당 방향에 더이상 없으면 방향을 튼다
    while (true){
        if (sX==initialeX && sY==initialeY){
            ans = min(ans, cost);
            break;
        }
        
        if (field[sX+dx[dIdx]][sY+dy[dIdx]]) {
            // 해당 방향으로 길이 더 있으면
            sX += dx[dIdx];
            sY += dy[dIdx];
            cout << sX << " " << sY << "이동\n";
        } else {
            // 방향을 틀어야 된다면
            for (int d=0; d<4; d++){
                if (d!=inverse[dIdx] && field[sX+ dx[d]][sY+ dy[d]]){
                    dIdx= d;
                    sX += dx[d];
                    sY += dy[d];
                    cout << sX << " " << sY << "방향 이동\n";
                }
            }
        }
        cost++;
        // if (cost==30) break;
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    initialsX= characterX*2; initialsY= characterY*2;
    initialeX= itemX*2; initialeY= itemY*2;
    // 주어진 직사각형 정보를 꼭짓점에 대한 좌표계로 변환
    // 이떄 좌표 확장을 통해 실제로는 떨어져 있는 직사각형이 붙어있다고 착각하지 않게 할 수 있음
    // 1: 해당 꼭짓점이 직사각형 위에 있음
    
    for (int i= 0; i<rectangle.size(); i++) {
        int leftX= rectangle[i][0]*2; int leftY= rectangle[i][1]*2;
        int rightX= rectangle[i][2]*2; int rightY= rectangle[i][3]*2;
        int xLth = rightX-leftX; int yLth = rightY-leftY;
        
        // 일단 모든 변들을 1로 만드는 작업 우선
        for (int j=0; j<=xLth; j++){
            field[leftX+j][leftY]= 1;
            field[leftX+j][rightY]= 1;
        }
        
        for (int j=0; j<=yLth; j++){
            field[leftX][leftY+j]= 1;
            field[rightX][leftY+j]= 1; 
        }
    }
    
    // 내부 파내기 (모든 직사각형에 대해 내부를 0으로 만든다)
    for (int i=0; i<rectangle.size(); i++){
        int leftX= rectangle[i][0]*2; int leftY= rectangle[i][1]*2;
        int rightX= rectangle[i][2]*2; int rightY= rectangle[i][3]*2;
        int xLth = rightX-leftX; int yLth = rightY-leftY;
        
        for (int x=leftX+1; x<rightX; x++){
            for (int y= leftY+1; y< rightY; y++){
                field[x][y]=0; //0으로 덮어버린다.
            }
        }
    }
    print();
    
    // 출발점에서 도착점으로 간다
    // 2가지 방향이 있을 수 있으므로 두 번 가서 최솟값을 출력한다.
    
    for (int d=0; d<4; d++){
        if (field[initialsX+ dx[d]][initialsY+ dy[d]]){
            find(d);
        }
    }
    
    return ans/2;
}