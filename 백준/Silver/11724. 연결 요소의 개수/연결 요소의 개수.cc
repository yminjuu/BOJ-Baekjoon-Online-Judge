#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int start);

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N,M;
    cin >> N >> M;
    int tmpA, tmpB;

    A.resize(N+1);
    visited = vector<bool>(N+1, false);

    for (int i=0; i<M; i++){
        cin >> tmpA >> tmpB;
        A[tmpA].push_back(tmpB);
        A[tmpB].push_back(tmpA);
    }

    int result =0;

    for (int i=1; i<=N; i++){
        if (!visited[i]) {
            result++;
            DFS(i);
        }
    }

    cout << result;

   return 0;
}

void DFS(int start){
    for (int i=0; i<A[start].size(); i++){
        int vertex = A[start][i];
        if (!visited[vertex]){
            visited[vertex]= true;
            DFS(vertex);
        }
    }
    return;
}