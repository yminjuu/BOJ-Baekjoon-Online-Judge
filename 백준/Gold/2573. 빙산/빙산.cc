#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <cstring>

using namespace std;
using p = pair<int,int>;

int N,M;
int arr[305][305];
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
bool flag= true;

void melt(){
    int tmp[305][305]; // 결과를 미리 반영해버리면 연쇄적으로 결과가 전부 바뀜..
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (arr[i][j]==0) {tmp[i][j]= arr[i][j]; continue;}

            int seas=0;
            for (int k=0; k<4; k++){
                int newX= i+dx[k]; int newY= j+dy[k];
                if (arr[newX][newY]==0) seas++;
            }

            tmp[i][j]= max(0, arr[i][j]-seas);
        }
    }

    // 원본에 이때야 반영
    memcpy(arr, tmp, sizeof(tmp));
}

// dfs를 통해 덩어리의 개수를 카운팅한다
int count(){
    int visited[N+1][M+1];
    fill(&visited[0][0], &visited[N][M]+1, 0);

    int cnt=0; flag= true;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            // 새로운 덩어리 발견
            if (arr[i][j]!=0 && !visited[i][j]) {
                flag= false;

                // stack을 통한 dfs 구현
                stack<p> stck;
                stck.push({i,j});
                visited[i][j]= 1;

                while (!stck.empty()){
                    int x= stck.top().first;
                    int y= stck.top().second;
                    stck.pop();

                    for (int k=0; k<4; k++){
                        int newX= x+dx[k];
                        int newY= y+dy[k];

                        if (arr[newX][newY]!=0 && !visited[newX][newY]) {
                            visited[newX][newY]=1;
                            stck.push({newX, newY});
                        }
                    }
                }
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int time=0;
    while (true){
        time++;
        // 1. 녹인다
        melt();

        // 2. 덩어리의 개수를 센다
        int res = count();
        
        // 2-1. 덩어리의 개수가 2 이상이면 time 출력 후 break
        if (res>=2) {
            cout << time;
            break;
        }

        // 2-2. 모든 빙산이 녹았으면 0 출력 후 break
        if (flag) {
            cout << 0;
            break;
        }
    }

   return 0;
}