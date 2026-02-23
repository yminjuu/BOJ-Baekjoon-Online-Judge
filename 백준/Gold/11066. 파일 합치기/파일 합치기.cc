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
    fill(&dp[0][0], &dp[K][K], INT_MAX);
    
    for (int i=0; i<K; i++){
        cin >> cost[i];
        dp[i][i]= 0; // 합치는 비용 0
    }

    for (int length= 1; length < K; length++){
        for (int start= 0; start+length< K; start++){
            for (int mid= start; mid<start+length; mid++){
                dp[start][start+length] = (min(dp[start][start+length], abs(dp[start][mid]+dp[mid+1][start+length])));
            }
            for (int i=start; i<=start+length; i++){
                dp[start][start+length]+= cost[i];
            }
        }
    }

    cout << dp[0][K-1] << "\n";
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
