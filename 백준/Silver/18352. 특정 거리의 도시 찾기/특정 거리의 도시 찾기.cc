#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> edge;
queue<int> q;
int visited[300001];
int N, M, K, X;

void BFS(){
    while (!q.empty()){
        int node = q.front(); q.pop();
        
        for (int i=0; i<edge[node].size(); i++){
            int newNode = edge[node][i];
            
            if (visited[newNode]==-1){
                visited[newNode] = visited[node]+1;
                q.push(newNode);
            }
        }   
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> N >> M >> K >> X;
    edge.resize(N+1);
    fill(visited, visited+N+1, -1);

    while (M--){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
    }

    q.push(X); visited[X]=0;
    BFS();

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=1; i<=N; i++){
        if (visited[i]==K) pq.push(i);
    }

    if (pq.empty()){
        cout << -1;
        return 0;
    }
    while (!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }

   return 0;
}
