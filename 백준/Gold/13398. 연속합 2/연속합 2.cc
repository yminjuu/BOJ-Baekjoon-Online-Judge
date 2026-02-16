#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
long dp[100001][2];
long vec[100001];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> vec[i];
    }

    dp[0][0] = max(vec[0], (long)0) ; dp[0][1] = vec[0];

    for (int i=1; i<N; i++){
        for (int k=0; k<2; k++){
            if (k==0){
                dp[i][0]= max(dp[i-1][0]+vec[i], vec[i]);
            }
            if (k==1) {
                dp[i][0] = max(dp[i][0], dp[i-1][1]); 
                dp[i][1] = max(dp[i-1][1]+vec[i], vec[i]);
            }
        }
    }

    long ans = LLONG_MIN;
    for (int i=0; i<N; i++){
        for (int j=0; j<2; j++){
            if (i==0 && j==0) continue;
            if (ans<dp[i][j]) ans=dp[i][j];
        }
    }

    cout << ans;
    
   return 0;
}