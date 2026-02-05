#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
typedef pair<int,int> p;
int V,E, startN;
vector<int> dist;
vector<vector<p>> vec;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> V >> E >> startN;
    dist.resize(V+1);
    vec.resize(V+1);
    fill(dist.begin(), dist.end(), INT_MAX);
    dist[startN]=0; 

    int u, v, w;
    while (E--){
        cin >> u >> v >> w;
        vec[u].push_back({v,w});
    }

    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, startN});
    while (!pq.empty()){
        p pp = pq.top(); pq.pop(); 
        for (int i=0; i<vec[pp.second].size(); i++){
            p nearN = vec[pp.second][i];
            if (dist[nearN.first] > pp.first + nearN.second){
                dist[nearN.first] = pp.first + nearN.second;
                pq.push({dist[nearN.first], nearN.first});
            }
        }
    }

    for (int i=1; i<=V; i++){
        if (dist[i]!=INT_MAX) cout << dist[i] << "\n";
        else cout << "INF\n";
    }

   return 0;
}
