#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define MOD 10007;

int N;
long ans = 0;
long dp[1001];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N;

    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for (int i=4; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    cout << dp[N];
    
   return 0;
}