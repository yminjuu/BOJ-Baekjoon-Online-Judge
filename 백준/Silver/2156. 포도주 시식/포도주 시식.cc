#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int n;
int dp[10001][3];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> vec(n+1);

    for (int i=1; i<=n; i++){
        cin >> vec[i];
    } 

    dp[0][0]=0; dp[0][1]= 0; dp[0][2]=0;
    
    for (int i=1; i<=n; i++){
        // 먹지 않는다
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        // 먹는다. 이전에 먹지 않았어야 한다.
        dp[i][1] = dp[i-1][0] + vec[i];

        // 먹는다. 이전에 먹어서 연속 2번이다.
        dp[i][2] = dp[i-1][1] + vec[i];
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    
   return 0;
}
