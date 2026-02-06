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
   
    int N;
    cin >> N;
    
    int dis[N+1][N+1];

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> dis[i][j];
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (!dis[i][j]) dis[i][j]= INF;
        }
    }

    for (int k=0; k<N; k++){
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                if (dis[i][j] > dis[i][k]+dis[k][j])
                    dis[i][j]= dis[i][k]+dis[k][j];
            }
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (dis[i][j]!=INF) cout << 1 << " ";
            else cout << 0 << " ";   
        }
        cout << "\n";
    }

   return 0;
}
