#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;

#define x first
#define y second

using p = pair<int,int>;

int arr[52][52];
vector<p> chickens;
vector<p> houses;
vector<long> dists;

long minDist= LLONG_MAX;
int visited[14];

// M(치킨집 개수)이 매우 작고, M의 조합을 결정하는 문제
// => 모든 경우에 대해 다 해본다 (백트래킹)

int N, M; 
// 0: 빈칸, 1: 집, 2: 치킨집

long count(){
    long ret= 0;
    for (int i=0; i<houses.size(); i++){
        long chickDist= LLONG_MAX;
        for (int j=0; j<chickens.size(); j++){
            if (visited[j]){
                long dist = abs(houses[i].x-chickens[j].x) + abs(houses[i].y-chickens[j].y);
                chickDist = min(chickDist, dist);
            }
        }
        // 이 조합일 때 이 집의 치킨거리를 구함
        ret += chickDist;
    }
    return ret;
}

void dfs(int startIdx, int cnt){
    if (cnt==M) {
        // 얘네만 남았을 때의 치킨 거리를 구해보고
        // 치킨 거리가 가장 작다면 갱신해준다
        long res= count();
        minDist = min(minDist, res);
        return;
    }

    for (int i=0; i<chickens.size(); i++){
        if (startIdx<i && !visited[i]){
            visited[i]= 1;
            dfs(i, cnt+1);
            visited[i]= 0;
        }
    }

    return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    
   
   cin >> N >> M;

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){ // 실수: 좌표 크기는 n*n 이다.
            cin >> arr[i][j];
            
            if (arr[i][j]==1) houses.push_back({i,j});
            else if (arr[i][j]==2) chickens.push_back({i,j});
            // 여기서 치킨집들의 인덱스는 전부 결정됨
        }
    }

    for (int i=0; i<chickens.size(); i++){
        visited[i]=1;
        dfs(i, 1); // i번째 치킨집을 포함하는 모든 경우의수를 해본다.
        visited[i]=0;
    }

    cout << minDist;
    
   return 0;
}