#include <string>
#include <vector>
#include <queue>

using namespace std;
using p= pair<int,int>;

int solution(vector<int> priorities, int location) {
    priority_queue<int, vector<int>> pq; // 우선순위 존재 확인용
    queue<p> q;
    
    for (int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    
    int idx=1; int ans;
    while (!pq.empty() || !q.empty()){
        if (pq.top() > q.front().first) {
            // 아직 못 넣음
            p process = q.front();
            q.pop();
            q.push(process);
        } else {
            if (q.front().second==location) {
                ans = idx;
                break;
            }
            pq.pop();
            q.pop();
            idx++;
        }
    }
    return ans;
}