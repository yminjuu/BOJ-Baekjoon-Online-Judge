#include <string>
#include <vector>
#include <queue>

using namespace std;

// 우선순위가 높다 = 숫자가 크다
// 인덱스마다 priority를 갖는다.
    // priority가 큰 순서 => 앞에 있는 순서

// struct cmp{
//     bool operator()(pair<int,int> &a, pair<int,int> &b){
//         if (a.second==b.second) return a.first > b.first;
//         else return a.second < b.second;
//     }
// };

int solution(vector<int> priorities, int location) {
    priority_queue<int, vector<int>> pq; // 가장 큰 원소가 맨 위, pq
    deque<int> dq;
    
    for (int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        dq.push_back(i); // 인덱스를 넣음 (순서 자체)
    }
    
    int answer=1; int idx=0;
    while (true){
        if (priorities[dq.front()]!=pq.top()){
            int tmp= dq.front();
            dq.pop_front();
            dq.push_back(tmp);
            // 건너뛰기
        } else {
            if (dq.front()==location) return answer;
            else {
                // 실행
                dq.pop_front();
                pq.pop();
                answer++;
            }
        }
    }
}