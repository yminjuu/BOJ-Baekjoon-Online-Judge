#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
using ll= long long;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;

    int A[N+1][2];
    for (int i=1; i<=N; i++) cin >> A[i][0] >> A[i][1];

    ll D[N+1][N+1];
    // D[i][j]: i~j 구간의 행렬곱을 구하는 데 드는 최소 연산수

    // 초기화
    for (int i=1; i<=N; i++){
            D[i][i]= 0;
        }

   for (int i=1; i<=N; i++){
       for (int j=1; i+j<=N; j++){
           
           // D[j][j+i]를 구한다.
           ll mn= LLONG_MAX;
           for (int k=0; k<i; k++){
                mn= min(mn, D[j][j+k]+D[j+k+1][i+j] + A[j][0]*A[j+k][1]*A[i+j][1]);
           }
           D[j][j+i]= mn;
       }
   }

    cout << D[1][N];

   return 0;
}
