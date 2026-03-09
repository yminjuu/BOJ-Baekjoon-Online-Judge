#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define MAX 987654321

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M, X;
    cin >> N >> M >> X;

    int path[1002][1002]; // 인접 배열
    fill(&path[0][0], &path[1001][1001]+1, MAX); // 초기화
    
    for (int i=1; i<=N; i++){
        // 자기 자신 초기화
        path[i][i]= 0;
    }
    
    while (M--){
        int s, e, t;
        cin >> s >> e >> t;
        path[s][e]= t;
    }

    // 플로이드워셜 적용
    for (int k= 1; k<=N; k++){ // 경유지 k
        for (int s= 1; s<=N; s++){
            for (int e=1; e<=N; e++){
                path[s][e] = min(path[s][e], path[s][k]+path[k][e]);
            }
        }
    }

    int cost[N+1];
    int mx = 0;
    for (int i=1; i<=N; i++){
        cost[i] = path[i][X]+ path[X][i];
        mx = max(cost[i], mx);
    }

    cout << mx;

   return 0;
}
