#include <queue>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
using p = pair<int,int>;

int N, K, L;
int arr[32][32]; // 현재 격자
bool hasRobot[32][32]; // 로봇이 있는지 여부를 확인하는 arr
queue<p> vaccums; // 로봇 청소기 위치 저장

// 행이 작은 순서, 열이 작은 순서
int dx[4]= {-1,0,0,1};
int dy[4]= {0,-1,1,0};

// 뺄 격자의 위치 순서대로 (뒤에 있을수록 우선순위 높음, 바로 갱신됨)
int newDx[4]= { 1,0,-1,0}; 
int newDy[4]= {0,1,0,-1}; 

// 전체 sum 구해서  출력
void print(){
    long sum=0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (arr[i][j]>=1) sum+= arr[i][j];
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }
    cout << sum << "\n";
}

// 4. 먼지 확산
// 동시 확산되지 않는다. 우선 copy에 이동시켜놓은뒤 복사한다.
void diffusion(){
    int newArr[32][32];
    memcpy(newArr, arr, sizeof(arr));

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (arr[i][j]!=0) continue;
            int sum=0;
            for (int d=0; d<4; d++){
                int newX= i+dx[d]; int newY= j+dy[d];
                if (newX>=1 && newY>=1 && newX<=N && newY<=N){
                    if (arr[newX][newY]>=1) sum+=arr[newX][newY];
                }
            }
            // cout << i << " " << j << sum << "확산\n";
            newArr[i][j]= sum/10;
        }
    }

    memcpy(arr, newArr, sizeof(arr)); //동시확산 반영
}

// 3. 먼지 축적
// 먼지가 있다면 +5씩
void accumulate(){
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (arr[i][j]>=1) arr[i][j] += 5;
        }
    }
}

// 2 sub 함수
// 4가지 방향에 대해 먼지량 합을 구해서 방문 순서를 반환
// 예) 0,1,2,3: (오->아->왼->위 기본값)
int findDirection(int r, int c){
    int mn = 101; int dIdx= 0;
    for (int d=0; d<4; d++){
        int newR= r+newDx[d]; int newC= c+newDy[d];
        if (newR>=1 && newR<=N && newC>=1 && newC<=N){
            if (mn >= min(20, arr[newR][newC])){ // 같아도 바로 갱신함.
                mn= min(20, arr[newR][newC]); // 최대 치울 수 있는 양
                dIdx= d; 
            }
        } else {
            // 격자 밖도 고려사항에 포함시킴
            if (mn >= 0) {
                mn= 0;
                dIdx= d;
            }
        }
        // 뺄 인덱스 d를 반환할 거임
    }
    return dIdx;
}

// 2. 청소
// 모든 청소기에 대해 방향을 구해서 그 순서대로 청소 진행
void clean() {
    int qSize = vaccums.size();
    for (int i = 0; i < qSize; i++) {
        auto [r, k] = vaccums.front(); vaccums.pop();
        int dir = findDirection(r, k); // 제외할 칸 인덱스

        // 현재 칸 청소 (먼지가 있을 때만)
        if (arr[r][k] > 0) arr[r][k] = max(arr[r][k] - 20, 0);

        for (int d = 0; d < 4; d++) {
            if (d == dir) continue;
            int nR = r + newDx[d];
            int nK = k + newDy[d];
            if (nR >= 1 && nR <= N && nK >= 1 && nK <= N) {
                if (arr[nR][nK] > 0) { 
                    // 먼지가 있을 때만 청소
                    arr[nR][nK] = max(arr[nR][nK] - 20, 0);
                }
            }
        }
        vaccums.push({r, k});
    }
}

void move() {
    int qSize = vaccums.size();
    for (int i = 0; i < qSize; i++) {
        auto [curR, curC] = vaccums.front(); 
        vaccums.pop();

        hasRobot[curR][curC] = false;

        // 테스트가 여러번 돌며 이미 로봇이 위치한 칸에 먼지가 있을 수도 있다.
        // L > 1일 때의 함정..!!!
        if (arr[curR][curC] > 0) {
            vaccums.push({curR, curC});
            hasRobot[curR][curC] = true;
            continue;
        }

        queue<p> q;
        q.push({curR, curC}); // q 기반 BFS
        int visited[32][32];
        memset(visited, 0, sizeof(visited));
        visited[curR][curC] = 1;

        bool found = false; // 하나를 찾았다면 동일 거리에 있는 모든 칸을 찾기 위해 저장.
        vector<p> candidates; // 동일한 최단 거리에 있는 먼지 칸들 저장
        int targetR = curR, targetC = curC;

        while (!q.empty()) {
            int stepSize = q.size(); // 현재 기준이 되는 거리 (0부터 시작)
            
            while (stepSize--) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // 범위 체크 & 방문 체크
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !visited[nx][ny]) {
                        // 장애물이나 다른 로봇이 있는 칸은 pass
                        if (arr[nx][ny] == -1 || hasRobot[nx][ny]) continue;

                        visited[nx][ny] = 1;

                        if (arr[nx][ny] > 0) {
                            // 먼지 발견 => 후보군에 추가하고 이번 레벨까지만 탐색
                            candidates.push_back({nx, ny});
                            found = true;
                        } else {
                            // 빈칸이면 다음 거리 탐색을 위해 큐에 삽입
                            q.push({nx, ny});
                        }
                    }
                }
            }
            
            if (found) {
                // pair<int,int> 각각 작은 순서대로 (행->열)
                sort(candidates.begin(), candidates.end());
                targetR = candidates[0].first;
                targetC = candidates[0].second;
                break; 
            }
        }

        vaccums.push({targetR, targetC});
        hasRobot[targetR][targetC] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> L;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<K; i++){
        int r, c;
        cin >> r >> c;
        vaccums.push({r,c}); // 순서대로 삽입
        hasRobot[r][c]= 1;
    }

    // 테스트 반복
    for (int i=0; i<L; i++){
        move();
        clean();
        accumulate();
        diffusion();
        print();
    }

    return 0;
}