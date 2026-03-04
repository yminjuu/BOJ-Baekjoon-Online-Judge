#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
const long long INF = 1e15;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    vector<int> num(N+1);
    for (int i=1; i<=N; i++) cin >> num[i];

    // dp[i][j][0]: i번째 수를 포함하지 않고 j개 구간 완성
    // dp[i][j][1]: i번째 수를 포함하여 j개 구간 완성
    static long long dp[3001][1501][2];

    // 초기화: 모든 경우를 불가능 설정
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=M; j++){
            dp[i][j][0]= dp[i][j][1] = -INF;
        }
    }

    // i가 0일 때: 0개를 선택한 합은 언제나 0
    for (int i=0; i<=N; i++) dp[i][0][0]= 0;

    // dp
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            // 1. i번째 수를 포함하지 않음
            dp[i][j][0]= max(dp[i-1][j][0], dp[i-1][j][1]);

            // 2. i번째 수를 포함함
            // 2-1. 연장: j개를 유지하며 이 값을 더함
            // 2-2. 신규: i-1에서 j-1개를 만든 상태를 가져와 j번째 바구니 신규 투입
                // 왜 i-1에서 j개의 바구니를 만든 상태를 가져오면 안될까?
            dp[i][j][1]= max(dp[i-1][j][1]+ num[i], dp[i-1][j-1][0] + num[i]);
        }
    }

    cout << max(dp[N][M][0], dp[N][M][1]);

   return 0;
}
