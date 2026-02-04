#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<int> times; // 짓는 데 걸리는 시간 
vector<int> ans; // 정답
vector<vector<int>> A; // 그 건물 짓기 전 지어야 하는 건물
vector<int> indegree; // 진입 차수 저장

queue<int> q;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
   cin >> N;

    times.resize(N+1);
    ans.resize(N+1);
    A.resize(N+1);
    indegree.resize(N+1);
    fill(indegree.begin(), indegree.end(), 0);

    for (int i=1; i<=N; i++){
        int t; cin >> t; times[i]=t; ans[i]= t;
        while (true){
            int a; cin >> a;
            if (a==-1) break;
            A[a].push_back(i);
            indegree[i]++;
        }
    }

    for (int i=1; i<=N; i++){
        if (indegree[i]==0) q.push(i);
    }

    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int i=0; i<A[node].size(); i++){
            int idx = A[node][i];
            indegree[idx]--;
            int newTime = ans[node] + times[idx]; // 시간 갱신

            if (newTime!= times[idx] && newTime > ans[idx]){
                ans[idx]= newTime;
            }
            if (indegree[idx]==0) q.push(idx);
        }
    }

    for (int i=1; i<=N; i++){
        cout << ans[i] << "\n";
    }

   return 0;
}
