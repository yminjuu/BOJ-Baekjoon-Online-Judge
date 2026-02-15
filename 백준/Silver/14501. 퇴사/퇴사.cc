#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

long dp[16];
long tm[16];
long profit[16];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    int N;
    cin >> N;

    for (int i=1; i<=N; i++){
        int t, p;
        cin >> t >> p;
        if (i+t-1>N) continue;
        else {
            tm[i]= t;
            profit[i]= p;
        }
    }

    for (int i=N; i>0; i--){
        if (!tm[i]) dp[i] = dp[i-1];

        dp[i]= max(profit[i]+dp[i+tm[i]], dp[i+1]);
    }

    cout << dp[1];

   return 0;
}
