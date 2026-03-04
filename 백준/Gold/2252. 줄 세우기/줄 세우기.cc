#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<int> vec[32001]; // 연결된 노드를 저장
int indegree[32001]; // 진입 차수를 저장

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    while (M--){
        int a,b;
        cin >> a >> b;
        vec[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;
    for (int i=1; i<=N; i++){
        if (indegree[i]==0) {
            q.push(i);
        }
    }

    while (!q.empty()){
        int startNode = q.front();
        cout << startNode << " ";
        q.pop();

        for (int i=0; i<vec[startNode].size(); i++){
            int nextNode = vec[startNode][i];
            indegree[nextNode]--;
            if (indegree[nextNode]==0) q.push(nextNode);
        }
    }

   return 0;
}
