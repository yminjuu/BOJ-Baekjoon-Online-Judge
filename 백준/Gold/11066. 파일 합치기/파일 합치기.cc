#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int K;

void file(){
    cin >> K;
    int dp[K+1][K+1];
    int cost[K+1];
    int sum[K+1]; // 구간합을 미리 구해둠
    fill(&dp[0][0], &dp[K][K], INT_MAX);

    sum[0]=0;
    for (int i=1; i<=K; i++){
        cin >> cost[i];
        sum[i]= sum[i-1]+cost[i];
        dp[i][i]= 0; // 합치는 비용 0
    }

    for (int length= 1; length < K; length++){
        for (int start= 1; start+length<= K; start++){
            for (int mid= start; mid<start+length; mid++){
                dp[start][start+length] = (min(dp[start][start+length], abs(dp[start][mid]+dp[mid+1][start+length])));
            }
            dp[start][start+length]+= (sum[start+length]- sum[start-1]);
        }
    }

    cout << dp[1][K] << "\n";
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int T;
    cin >> T;

    while (T--) file();

   return 0;
}
