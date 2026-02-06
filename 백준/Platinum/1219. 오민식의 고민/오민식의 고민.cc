#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

#define mINF -987654321
#define INF 987654321
typedef tuple<int, int, long> tup;

vector<tup> trans;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M, sCity, eCity; 
   cin >> N >> sCity >> eCity >> M;

    vector<long> cost(N+1, mINF);

    while (M--){
        int a,b,c;
        cin >> a >> b >> c;
        trans.push_back(make_tuple(a,b,-c));
    }

    int node = 0;
    while (node != N){
        int a; // 버는 돈
        cin >> a;
        for (int i=0; i<trans.size(); i++){
            tup t = trans[i];
            if (get<1>(t)== node) {
                get<2>(trans[i]) = get<2>(t) + a;
            }
            if (node==sCity) cost[sCity] = a;
        }
        node++;
    }

        for (int i=0; i<N-1; i++){
                for (int k=0; k<trans.size(); k++){
                    tup t = trans[k];
                    int start = get<0>(t); 
                    int end = get<1>(t);
                    long w = get<2>(t);

                    if (cost[start]!=mINF && (cost[start] + w > cost[end])){
                        cost[end] = cost[start] + w;
                    }
                }
        }   


     for (int i=0; i<50; i++){
                for (int k=0; k<trans.size(); k++){
                    tup t = trans[k];
                    int start = get<0>(t); 
                    int end = get<1>(t);
                    long w = get<2>(t);

                    if (cost[start]==INF) cost[end]= INF;
                    if (cost[start]!=mINF && (cost[start] + w > cost[end])){
                        // 방문 가능한 점인데 가중치가 갱신된다
                        cost[end] = INF;
                    }
                }
        }   

    if (cost[eCity]==INF) cout << "Gee";
    else if (cost[eCity]==mINF) {
        cout << "gg";
    } else cout << cost[eCity];
    
   return 0;
}
