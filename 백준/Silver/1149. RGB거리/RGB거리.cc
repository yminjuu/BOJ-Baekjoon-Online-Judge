#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
int cost[1002][3]; // rgb로 칠하는 비용
long ans = LLONG_MAX;

int N;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N;

    long dp[N+2][3];
    fill(&dp[0][0], &dp[N+2][3]+1, LLONG_MAX);

    for (int i=0; i<N; i++){
        for (int j=0; j<3; j++){
            cin >> cost[i][j];
        }
    }

    for (int i=0; i<3; i++){
        dp[0][i]= cost[0][i]; // 초깃값
    }

    int near[3][2] = {
    {
    1,2
    },
    {
    0,2
    },
    {
    0,1
    }
    };
    
    for (int i=1; i<N; i++){
        for (int j=0; j<3; j++){
            dp[i][j] = min(dp[i-1][near[j][0]], dp[i-1][near[j][1]]) + cost[i][j];
        }
    }

    for (int i=0; i<3; i++){
        ans = min(dp[N-1][i], ans);
    }
    
    cout << ans;

   return 0;
}
