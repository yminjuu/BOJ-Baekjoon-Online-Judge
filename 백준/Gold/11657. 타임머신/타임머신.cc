#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int N, M, A, B, C;
long long Dist[502];
const long long INF = 987654321;

struct edge {
    int from;
    int to;
    int dist;
};

edge Edge[6002];

void bellman(){
    for (int i=1; i<N; i++){
        for (int j=0; j<M; j++){
            if (Dist[Edge[j].from]!=INF){
                if (Dist[Edge[j].to]>Dist[Edge[j].from]+Edge[j].dist){
                    Dist[Edge[j].to]= Dist[Edge[j].from]+Edge[j].dist;
                }
            }
        }
    }
    for (int i=1; i<N; i++){
        for (int j=0; j<M; j++){
            if (Dist[Edge[j].from]!=INF){
                if (Dist[Edge[j].to]>Dist[Edge[j].from]+Edge[j].dist){
                    cout << -1;
                    return;
                }
            }
        }
    }
    for (int i=2; i<=N; i++){
        if (Dist[i]==INF) cout << "-1" << "\n";
        else cout << Dist[i] << "\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    fill_n(Dist, N+1, INF);
    for (int i=0; i<M; i++){
        edge e;
        cin >> e.from >> e.to >> e.dist;
        Edge[i]=e;
    }
    Dist[1]=0;
    bellman();

    return 0;
}