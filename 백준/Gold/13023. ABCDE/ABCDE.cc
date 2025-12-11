#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

static int N, M;
static vector<vector<int>> A;
static vector<bool> visited;
static bool result = false;
void DFS(int num, int depth);

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> N >> M; 
    int tmpA, tmpB;
    A= vector<vector<int>>(N+1);
    visited = vector<bool>(N+1, false);

    // 인접리스트
   for (int i=0; i<M; i++){ 
       cin >> tmpA >> tmpB;
       A[tmpA].push_back(tmpB);
       A[tmpB].push_back(tmpA);
   }

    for (int i=0; i<N; i++){
        visited[i] = true;
        DFS(i, 1);
        visited[i]= false;
    }

    cout << result;
    
   return 0;
}

void DFS(int num, int depth){
   if (depth==5) {
       result= true;
       return;
   }
    
    for (int i=0; i<A[num].size(); i++){
        int vertex = A[num][i];
        if (!visited[vertex]) {
            visited[vertex]= true;
            DFS(vertex, depth+1);
            visited[vertex]= false;
        }
        if (result) break;
    } 
    return;
}
