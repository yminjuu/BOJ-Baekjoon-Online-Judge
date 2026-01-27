#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int V; 
typedef pair<int, int> edge;
static vector<vector<edge>> vec; 
int visited[100001];
int dist[100001]; 
queue<int> q;
void findDist(int v);

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> V;
   vec.resize(V+1); 

    int nodeNum; int nodePairNum; int dis;
   for (int i=0; i<V; i++){
        cin >> nodeNum;
        while (true){
            cin >> nodePairNum;
            if (nodePairNum==-1) break;
            cin >> dis;
            vec[nodeNum].push_back(edge(nodePairNum, dis));
        }
   }

   visited[2]= 1;
   findDist(2);

   int mxIdx = 1;
   for (int i=1; i<=V; i++){
        if (dist[mxIdx]<dist[i]) mxIdx= i;
   }

   fill(visited, visited+V+1, 0);
   fill(dist, dist+V+1, 0);

   visited[mxIdx] = 1;
   findDist(mxIdx);

   mxIdx = 1;
   for (int i=1; i<=V; i++){\
        if (dist[mxIdx]<dist[i]) mxIdx= i;
   }
   cout << dist[mxIdx];


   return 0;
}

void findDist(int v) {
    q.push(v);

    while (!q.empty()){
        int currNode = q.front(); q.pop();

         for (int i=0; i< vec[currNode].size(); i++){
            int idx = vec[currNode][i].first;
            if (visited[idx]) continue;
            q.push(idx); 
            visited[idx]=1; 
            dist[idx] = dist[currNode] + vec[currNode][i].second;
        }
    }
}