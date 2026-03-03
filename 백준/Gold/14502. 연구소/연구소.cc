#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

#define x first
#define y second

using namespace std;
using p = pair<int,int>;

int N, M; // 매우 작다 최대 (3,8)
int arr[10][10];
int tmp[10][10];
int safeAns=0; // 안전 영역 크기 저장

int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};

int visited[10][10];
vector<p> candidates; // 모든 벽 세우기 가능한 바이러스 인접벽들의 좌표를 저장
vector<p> selected;

void print(){
    for (int i=0; i<N; i++){
        for (int j=0; j<M ;j++){
            cout << tmp[i][j] << " ";
        }
        cout <<"\n";
    }
}

void spreadVirus(int x, int y){
    for (int d=0; d<4; d++){
        int newX= x+dx[d]; int newY= y+dy[d];
        if (newX>=0 && newX<N && newY>=0 && newY<M && tmp[newX][newY]==0){
            visited[newX][newY]= 1;
            tmp[newX][newY]=2;
            spreadVirus(newX, newY);
        }
    }
}

int spreadVirusAndCnt(){
    memcpy(tmp, arr, sizeof(arr)); // 2번째 인자가 원본

    for (int i=0; i<3; i++){
        int wallX= selected[i].x; int wallY = selected[i].y;
        tmp[wallX][wallY]= 1;
    }

    fill(&visited[0][0], &visited[9][9]+1, 0);

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (tmp[i][j]==2 && !visited[i][j]){
                visited[i][j]=1;
                spreadVirus(i,j);
            }
        }
    }

    int ret =0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (tmp[i][j]==0) ret++;
        }
    }
    return ret;
}

void dfs(int startIdx, int cnt){
    if (cnt==3){
        int res = spreadVirusAndCnt();
        safeAns= max(res, safeAns);
        return;
    }

    for (int i=startIdx+1; i<candidates.size(); i++){
        selected.push_back({candidates[i].x, candidates[i].y});
        dfs(i, cnt+1);
        selected.pop_back();
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
            if (arr[i][j]==0) candidates.push_back({i,j});
        }
    }

    for (int i=0; i<candidates.size(); i++){
        selected.push_back({candidates[i].x, candidates[i].y});
        dfs(i, 1);
        selected.pop_back();
    }

    cout << safeAns;

   return 0;
}