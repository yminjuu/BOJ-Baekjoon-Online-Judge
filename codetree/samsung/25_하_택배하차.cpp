/**
 * 풀이 시간: 2H
 * 풀이 아이디어: 중력에 의한 시뮬레이션 적용, 방향에 맞게 박스를 떨어뜨리고 좌우로 빼낸다
 * 풀이하며 실수했던 부분 (1) 지우고 찾기 -> 박스를 없애고 나머지를 떨어뜨릴 때, 나 자신은 참조하지 않게 한다 (장애물이 되지 않게)
 * (2) 내가 건드린 부분만 바뀌지 않음. width 1짜리 박스 위에 width 100짜리 박스가 있는 예외를 생각했어야 함.
 */

#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define MAX 105

struct Box {
    int h, w, c;
};

int N,M;
int arr[52][52];
map<int, Box> mp;
int boxBasis[102];

// 왼쪽 시작 열과 바닥 행을 기준으로 arr에서 지워주는 함수
void take(int k){
    Box box = mp[k];
    for (int i= boxBasis[k]; i> boxBasis[k]-box.h; i--){
        for (int j= box.c; j< box.c+ box.w; j++){
            arr[i][j]= 0;
        }
    }
}

// 현재 바닥 행을 기준으로 arr에 채워주는 함수
void fill(int k){
    Box box = mp[k];
    // boxBasis를 참조
    for (int i= boxBasis[k]; i> boxBasis[k]-box.h; i--){
        for (int j= box.c; j< box.c+ box.w; j++){
            arr[i][j]= k;
        }
    }
}

// 중력에 의해 떨어짐
void fallDown(int k, int basis){
    int floor= max(basis, 0); 

    Box box = mp[k];
    int w = box.w; int c = box.c;

    if (basis!=-1) take(k); // 초기 들어오는 것이 아니라면 우선 기존 위치 제거

    if (basis==-1) basis=0;
    for (int i= basis+1; i<=N; i++){ // 행
        bool isEmpty = true;
        for (int j=c; j<c+w; j++){
            if (arr[i][j]){ isEmpty= false; break;}
        }
        if (isEmpty) {
            floor++;
        } else break;
    }

    boxBasis[k]= floor; // 새로운 바닥 위치
    fill(k); // 채운다
}

// 모든 높이에 대해서 뺴낼 수 있는지 확인
bool isAvailableToTakeOut(int k, int weight){
    Box box = mp[k];

    bool isAvailable= true;
    for (int row= boxBasis[k]- box.h+1; row<= boxBasis[k] && isAvailable; row++){
        // 모든 행에 대해
        int basis = (weight==1 ? box.c+box.w : box.c-1);
        for (int col= basis; (col>=1 && col<=N); col+= weight){
            if (arr[row][col]) {
                isAvailable= false; // 막혀있음
                break;
            }
        }
    }

    return isAvailable;
}

bool takeOut(int startCol){
    int weight = (startCol==1 ? 1 : -1);
    int minBoxIdx= MAX; // 실수: 

    // (1) 빼낼 수 있는 최적의 박스를 찾는다
    for (int row= 1; row<=N; row++){
        for (int col= startCol; (col>=1 && col<=N); col+=weight){
            int boxnum = arr[row][col];
            if (boxnum && isAvailableToTakeOut(boxnum, -1*weight)) {
                minBoxIdx = min(minBoxIdx, boxnum);
                break;
            }
        }
    }

    // 만약 끝까지 살폈는데 하나도 없다면 false를 바로 반환
    if (minBoxIdx==MAX) return false;

    // (2) 뺀다.
    cout << minBoxIdx << "\n";
    take(minBoxIdx); // 빼냄
    
    int h = mp[minBoxIdx].h; int w = mp[minBoxIdx].w; 
    int c = mp[minBoxIdx].c;

    // (3) 빼낸 후 처리 : 중력에 의한 움직임 (가장 밑에서부터 올라오며 모든 격자를 확인)
    int visited[102];
    fill(&visited[0], &visited[101]+1, 0);
    for (int row= N; row>=1; row--){
        for (int col= 1; col<=N ; col++){ // 논리오류: 기존 박스가 있던 칼럼만 확인해선 안됨, 전체 격자 확인 필요
            if (arr[row][col] && !visited[arr[row][col]]){
                fallDown(arr[row][col], boxBasis[arr[row][col]]);
                visited[arr[row][col]]=1;
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> M;

    for (int i=0; i<M; i++){
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        mp[k]= {h,w,c};

        fallDown(k, -1);
    }

    while (true){
        if (!takeOut(1)) break;
        if (!takeOut(N)) break;
    }

    return 0;
}