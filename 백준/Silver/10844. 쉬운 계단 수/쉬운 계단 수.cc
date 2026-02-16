#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define MOD 1000000000;
long dp[101][10];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;

    for (int i=1; i<=9; i++){
        dp[1][i]= 1;
    }

    for (int i=2; i<=N; i++){
        for (int j=0; j<=9; j++){
            if (j==0) dp[i][j]= dp[i-1][1];
            else if (j==9) dp[i][j]=dp[i-1][8];
            else dp[i][j]= (dp[i-1][j-1]+dp[i-1][j+1])%MOD;
        }
    }

    long sum=0;
    for (int i=0; i<=9; i++){
        sum= (sum+ dp[N][i]) % MOD;
    }

    cout << sum;
   return 0;
}
