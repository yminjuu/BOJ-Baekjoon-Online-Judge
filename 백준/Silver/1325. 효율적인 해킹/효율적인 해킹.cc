#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N,M;
vector<vector<int>> vec;
vector<bool> visited;

int BFS(int node){
    queue<int> q;
    q.push(node);
    visited[node]= true;

    int cnt=0;
    while (!q.empty()){
        node= q.front(); q.pop();
        for (int i=0; i<vec[node].size(); i++){
            int nextNode = vec[node][i];

            if (!visited[nextNode]){
                cnt++;
                q.push(nextNode);
                visited[nextNode]= true;
            }
        }
    }
    return cnt;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;
    vec.resize(N+1);
    visited.resize(N+1);
    
    while (M--){
        int a, b;
        cin >> a >> b;
        vec[b].push_back(a);
    }

    vector<int> ans(N+1);
    
    for (int i=1; i<=N; i++){
        fill(visited.begin(), visited.end(), false);
        ans[i]= BFS(i);
    }

    int mx=0;
    for (int i=1; i<=N; i++){
        if (ans[i]>mx) mx=ans[i];
    }
    vector<int> ansVec;
    for (int i=1; i<=N; i++){
        if (ans[i]==mx) ansVec.push_back(i);
    }
    sort(ansVec.begin(), ansVec.end());
    for (int i=0; i<ansVec.size(); i++){
        cout << ansVec[i] << " ";
    }

   return 0;
}
