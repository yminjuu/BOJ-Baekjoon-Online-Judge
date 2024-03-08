#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int N, M, A, B, C;
long long Dist[102][102];
const long long INF = 987654321;

void floyd(){
    for (int i=1; i<=N; i++){ //i번째 정점을 거칠 수 있음
        for (int j=1; j<=N; j++){
            for (int k=1; k<=N; k++){
                if (Dist[j][k]>Dist[j][i]+Dist[i][k]){
                    Dist[j][k] = Dist[j][i]+Dist[i][k];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (i==j) Dist[i][j]=0;
            else Dist[i][j]=INF;
        }
    }
    for (int i=0; i<M; i++){
        cin >> A >> B >> C;
        if (Dist[A][B]>C) Dist[A][B] = C;
    }
    floyd();
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (Dist[i][j]==987654321) cout << 0 << " ";
            else cout << Dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}