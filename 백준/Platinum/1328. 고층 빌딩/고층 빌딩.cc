#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
#define MOD 1000000007;
using namespace std;
long long dp[104][104][104];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, L, R;
    cin >> N >> L >> R;

    dp[1][1][1]= 1; // 1개의 빌딩을 배치한 상황
    for (int i=2; i<=N; i++){
        for (int l=1; l<=L; l++){
            for (int r=1; r<=R; r++){
                    // 1. 맨 앞에 둔다 L이 는다
                    dp[i][l][r] += dp[i-1][l-1][r];

                    // 2. 맨 뒤에 둔다 R이 는다
                    dp[i][l][r] += dp[i-1][l][r-1];

                    // 3. 그 사이 어디엔가 둔다
                    dp[i][l][r] += (dp[i-1][l][r]* (i-2)) % MOD;
                    dp[i][l][r]%= MOD;
            }
        }
    }

    cout << dp[N][L][R];

   return 0;
}
