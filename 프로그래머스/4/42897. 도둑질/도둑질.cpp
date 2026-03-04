#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
long dp[1000005][2];

int solution(vector<int> money) {
    int N= money.size();
    
     // 0과 N-1을 확인
    long ans = LLONG_MIN;
    
    // 0을 턴다 => 1을 털지 못한다.
    // 첫번째 집, 마지막 집을 빼고
    // 인덱스 1~N-2를 완성
    dp[1][1]= money[0]; // 1을 턴다
    for (int i=2; i<N; i++){
        // 안 턴다
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        
        // 턴다
        dp[i][1] =dp[i-1][0] + money[i-1];
        if (i==2) dp[i][1] = money[0]; // 1을 털었다고 가정했으므로 2번째 집은 털지 못한다
    }
    
    // 0을 털었을 때 마지막 집의 max 값 => 마지막 집은 털지 못함
    ans = max(dp[N-1][0], dp[N-1][1]); // 앞에서 결정된 값들 중 큰 것
    cout << ans << "\n";
    
    // 0을 털지 않는다
    dp[1][1]= 0;
    for (int i=2; i<N; i++){
        // 안 턴다
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        
        // 턴다
        dp[i][1] =dp[i-1][0] + money[i-1];
    }
    
    // 0을 털지 않았으므로 마지막 집을 털거나/ 털지 않거나 중 결정
    ans = max(ans, max(dp[N-1][0] + money[N-1], max(dp[N-1][0], dp[N-1][1])));
    cout << ans << "\n";
    
    return ans;
}