#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
int N, kMax;
vector<vector<int>> treeBase;

vector<int> visited;
vector<int> depth; // 노드 깊이 배열
int parent[21][100001]; // parent를 최대로 정의

int minParent(int a, int b){
    // 깊이가 같아질 때까지 깊은 쪽 노드를 위로 올린다.

    // b가 더 깊다고 가정
    if (depth[a]>depth[b]) swap(a,b); // b가 더 깊은 쪽

    int depthDiff = depth[b]-depth[a];
    for (int i=0; i<= kMax; i++){
        if ((depthDiff >> i) & 1){
            b = parent[i][b];
        }
    }

    if (a==b) return a; // 같으면 early return

    for (int k= kMax; k>=0 ; k--){
        if (parent[k][a]!=parent[k][b]){
            a= parent[k][a];
            b= parent[k][b];
            // 2씩 건너뛰기
        } 
    }

    // 이 시점의 a,b는 다르다. (혹은 루트다.)

    int LCA= a;

    if (a!=b){
        LCA = parent[0][LCA]; // 달랐다면 하나 위로 올려준다
    }

    return LCA;
}

// 연결된 모든 자식을 BFS로 탐색한다.
void BFS(int p){
    queue<int> q; q.push(p);

    while (!q.empty()){
        p = q.front(); q.pop();
         for (int i=0; i<treeBase[p].size(); i++){
            int c = treeBase[p][i];
            if (!visited[c]){
                parent[0][c] = p; // 2^0 부모 저장
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

    cin >> N;
    visited.resize(N+1);
    treeBase.resize(N+1);
    depth.resize(N+1);

    kMax= 0; int temp= 1;
    while (temp<=N){
        temp = temp << 1;
        kMax++;
    }

    for (int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        treeBase[a].push_back(b);
        treeBase[b].push_back(a);
    }

    // 루트(깊이 0)부터 DFS
    visited[1]= 1; depth[1]= 0;
    BFS(1);

    for (int i=1; i<=kMax; i++){
        for (int n=1; n<=N; n++){
            parent[i][n] = parent[i-1][parent[i-1][n]];
        }
    }

    int M;
    cin >> M;
    while (M--){
        int a, b;
        cin >> a >> b;
        cout << minParent(a,b) << "\n";
    }

   return 0;
}
