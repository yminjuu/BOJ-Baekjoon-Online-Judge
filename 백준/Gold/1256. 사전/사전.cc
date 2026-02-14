#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
int comb[201][201];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   ll N, M, K; 
   cin >> N >> M >> K;
    // 모든 문자열이 N개의 a와 M개의 z로 이루어짐

    // 조합 구성
    for (int i=1; i<=N+M; i++){
        comb[i][i]=1;
        comb[i][1]=i;
        comb[i][0]=1;
    }

    for (int i=1; i<=N+M; i++){
        for (int j=2; j<i; j++){
            comb[i][j] = (comb[i-1][j]+comb[i-1][j-1]);
            if (comb[i][j]> 1000000000) comb[i][j] =1000000001;;
        }
    }

    if (comb[N+M][N]<K) {
        cout << -1;
        return 0;
    }

    ll aCnt=0, zCnt=0; ll i; 
    for (i=N+M; i>0 && aCnt!=N && zCnt!=M ; i--){
        // a를 선택했다고 가정, 남은 카드를 결정하는 경우의 수
        if (K<=(comb[i-1][N-aCnt-1])){
            // a 선택이 맞음
            cout << "a";
            aCnt++;
        } else {
            // z를 선택해야 함
            K-= (comb[i-1][N-aCnt-1]);
            cout << "z";
            zCnt++;
        }
    }

    if (aCnt==N) {
        while (i--!=0){
            cout << "z";
        }
    } else {
        while (aCnt++!=N){
            cout << "a";
        }
    }

   return 0;
}
