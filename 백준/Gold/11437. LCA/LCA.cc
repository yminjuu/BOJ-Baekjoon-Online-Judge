#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
vector<vector<int>> treeBase;

vector<int> visited;
vector<int> depth; // 노드 깊이 배열
vector<int> parent; // 노드 부모 배열

int minParent(int a, int b){
    // 깊이가 같아질 때까지 깊은 쪽 노드를 위로 올린다.

    // b가 더 깊다고 가정
    if (depth[a]>depth[b]) swap(a,b); // b가 더 깊은 쪽

    // 깊이를 맞춘다
    while (depth[a]!=depth[b]){
        b = parent[b];
    }

    while (parent[a]!=parent[b]){
        a= parent[a];
        b= parent[b];
    }

    if (a==b) return a;
    else return parent[a];
}

// 연결된 모든 자식을 BFS로 탐색한다.
void BFS(int p){
    queue<int> q; q.push(p);

    while (!q.empty()){
        p = q.front(); q.pop();
         for (int i=0; i<treeBase[p].size(); i++){
            int c = treeBase[p][i];
            if (!visited[c]){
                parent[c] = p; // 부모 저장
                depth[c] = depth[p]+1; // 깊이 저장
                visited[c] = 1;
                q.push(c);
            }
        }   
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    visited.resize(N+1);
    treeBase.resize(N+1);
    depth.resize(N+1);
    parent.resize(N+1);

    for (int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        treeBase[a].push_back(b);
        treeBase[b].push_back(a);
    }

    // 루트(깊이 0)부터 DFS
    visited[1]= 1; depth[1]= 0;
    BFS(1);


    int M;
    cin >> M;
    while (M--){
        int a, b;
        cin >> a >> b;
        cout << minParent(a,b) << "\n";
    }

   return 0;
}
