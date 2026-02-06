#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define INF 987654321

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    long dis[N+1][N+1];
    
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            dis[i][j]= INF;
            if (i==j) dis[i][j]= 0;
        }
    }

    while (M--){
        int a, b,c;
        cin >> a >> b >> c;
        if (dis[a][b] > c)
            dis[a][b]= c;
    }

    for (int k=1; k<=N; k++){
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                if (dis[i][j] > dis[i][k]+dis[k][j])
                    dis[i][j]= dis[i][k]+dis[k][j];
            }
        }
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (dis[i][j]==INF) cout << 0 << " ";
            else cout << dis[i][j] << " ";
        }
        cout << "\n";
    }

   return 0;
}
