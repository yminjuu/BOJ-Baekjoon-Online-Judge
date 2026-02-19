#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int INF = 1000000 * 16 + 1;
int N;
int A[17][17];
int D[17][(1 << 16)]; // 비용을 저장

// c: 시작 도시
// v: 현재 방문한 도시를 이진수로 나타낸 값
long tsp(int c, int v){
    // 모든 도시를 방문했는지 확인
    if ((1 << N)-1 == v){
        return A[c][0]==0 ? INF : A[c][0]; // 말단까지 도달함 
    }

    // 이미 저장된 값이라면 return 
    if (D[c][v]!=0) return D[c][v];

    long mn= INF;
    for (int i=0; i<N; i++){
        if ((v & (1 << i))==0 && A[c][i]!=0){
            mn = min(tsp(i, v | (1 << i))+ A[c][i], mn);
        }
    }
    // 순차적으로 돌며 방문하지 않았고/ 방문할 수 있는 도시에 대해
    // 재귀함수 호출
    return D[c][v]= mn;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> N;
    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }

    cout << tsp(0,1); // 0번 도시부터 시작

   return 0;
}
