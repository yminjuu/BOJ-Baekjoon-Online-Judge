#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    long arr[N+1][N+1] = {0,};
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            arr[i][j] = 987654321;
        }
    }

    while (M--){
        int A, B;
        cin >> A >> B;
        arr[A][B] = 1;
        arr[B][A]= 1;
    }

    // 플로이드-워셜 알고리즘을 적용하여 모든 경유지를 순차탐색한다
    for (int k = 1; k<=N; k++){
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                if (arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j]= arr[i][k]+arr[k][j];
                }
            }
        }
    }

    vector<long> sum(N+1, 0);
    long mn=987654321;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (i!=j) sum[i]+= arr[i][j];
        }
        if (sum[i]<mn) mn= sum[i];
    }

    for (int i=1; i<=N; i++){
        if (sum[i]==mn) {
            cout << i;
            return 0;
        }
    }

   return 0;
}
