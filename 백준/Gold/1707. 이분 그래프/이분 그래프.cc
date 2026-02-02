#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int V,E;
vector<vector<int>> info;
vector<bool> visited;
vector<int> check;
bool isEven= true;

void DFS(int node){
    visited[node]= true;

    for (int n : info[node]){
        if (!visited[n]){
            check[n] = (check[node]+1)%2;
            DFS(n);
        } else if (check[n]==check[node]) {
            isEven= false;
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int K;
    cin >> K;
    while (K--){
        cin >> V >> E;

        info.resize(V+1);
        visited.resize(V+1);
        check.resize(V+1);
        isEven= true;

        for (int i=0; i<E; i++){
            int u,v;
            cin >> u >> v;
            info[u].push_back(v);
            info[v].push_back(u);
        }

        for (int i=1; i<=V; i++){
            DFS(i);
            if (!isEven) break;
        }

        if (isEven) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        for (int i=1; i<=V; i++){
            info[i].clear();
            visited[i]= false;
            check[i]= 0;
        }
    }

   return 0;
}