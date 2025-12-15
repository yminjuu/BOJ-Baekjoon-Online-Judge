#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
static vector<vector<int>> edge; // 데이터 배열
static vector<bool> visited;

void DFS(int vertex);
void BFS(int vertex, queue<int> &a);

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    int N, M, V;
    cin >> N >> M >> V;

    edge = vector<vector<int>>(N+1);
    visited = vector<bool>(N);
    queue<int> q;

    int a,b;
    for (int i=0; i<M; i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    // 정렬
    for (int i=1; i<=N; i++){
        sort(edge[i].begin(), edge[i].end());
    }

    visited= vector<bool>(N+1, false);
    DFS(V);
    cout << "\n";

    visited= vector<bool>(N+1, false);
    BFS(V, q);

   return 0;
}

void DFS(int vertex){
        cout << vertex << " ";
        visited[vertex]= true;
        for (int i=0; i< edge[vertex].size(); i++){
            int tmp = edge[vertex][i];
            if (!visited[tmp]) {
                DFS(tmp);
            }
        }
}

void BFS(int vertex, queue<int> &a){
    cout << vertex << " ";
    visited[vertex]= true;
    
    for (int i=0; i< edge[vertex].size(); i++){
        if (!visited[edge[vertex][i]]){
            a.push(edge[vertex][i]);
        }
    }
    
    while (!a.empty() && visited[a.front()]) a.pop();
    if (a.empty()) return;
    int tmp = a.front();
    a.pop();
    BFS(tmp, a);
}