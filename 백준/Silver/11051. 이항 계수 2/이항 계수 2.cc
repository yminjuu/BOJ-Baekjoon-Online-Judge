#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define MOD 10007;
int D[1001][1001];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, K;
   cin >> N >> K;

    for (int i=1; i<=N; i++){
        // 배열 초기화
        D[i][i]= 1; // 전부 뽑음
        D[i][1]= i; // 1개만 뽑음
        D[i][0]= 1; // 뽑지 않음
    }

    for (int i=1; i<=N; i++){
        for (int k=2; k<i; k++){
            D[i][k] = (D[i-1][k-1]+D[i-1][k]) % MOD;
        }
    }

    cout << D[N][K];
    
   return 0;
}
