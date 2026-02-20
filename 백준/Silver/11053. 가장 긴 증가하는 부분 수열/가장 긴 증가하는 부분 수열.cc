#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int N;
int A[1000002];
long dp[100002];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> N;

    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    dp[N-1]= 1; long mxTotal = 1;
    for (int i=N-2; i>=0; i--){
        // 내 뒤에 있고 나보다 큰 값들 중 가장 큰 값 + 1
        long mx = LLONG_MIN;
        for (int j=i+1; j<N; j++){
            if (A[i]< A[j]){
                mx = max(mx, dp[j]);
            }
        }
        if (mx!=LLONG_MIN) dp[i]= mx + 1;
        else dp[i]= 1; // 새로 시작
        mxTotal = max(dp[i], mxTotal);
    }
    cout << mxTotal;
}
