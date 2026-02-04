#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;
    vector<vector<int>> A;
    vector<int> indegree; // 진입 차수
    A.resize(N+1);
    indegree.resize(N+1);
    fill(indegree.begin(), indegree.end(), 0);

    while (M--){
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q; vector<int> ans;
    for (int i=1; i<=N; i++){
        if (!indegree[i]) {
            q.push(i);
            indegree[i]--;
            break;
        }
    }

    while (!q.empty()){
        int p = q.front(); q.pop(); ans.push_back(p);
        // 연결된 진입차수 감소시킴
        for (int i=0; i<A[p].size(); i++){
            indegree[A[p][i]]--;
        }
        // 다음으로 진입차수가 0인 애를 찾음
        for (int i=1; i<=N; i++){
            if (!indegree[i]) {
                indegree[i]--; // -1로 표시
                q.push(i);
                break;
            }
        }
    }

    for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";

   return 0;
}
