#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<vector<int>> edges;
vector<int> visited;
vector<int> parent;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;
    visited.resize(N+1);
    edges.resize(N+1);
    parent.resize(N+1);
    
    for (int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    visited[1]= 1; 
    queue<pair<int,int>> q; 
    q.push({1,1});
    
    while (!q.empty()){
        int p = q.front().first;
        int idx = q.front().second; 
        q.pop();

        int child= 0;
        for (int i=0; i<edges[p].size(); i++){
            int c = edges[p][i];
            if (visited[c]) continue;

            visited[c] = 1;
            q.push({c, idx*2+child});
            child++;
            parent[c] = p;
        }
    }

    for (int i=2; i<=N; i++){
        cout << parent[i] << "\n";
    }

   return 0;
}
