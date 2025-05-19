#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> &a, vector<int> &b) {
        if (a.back()==b.back()) return a.front() > b.front(); // 소요시간이 같으면
        else return a.back() > b.back(); // 소요시간이 짧은 것이 우선
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int tmp, time=0;
    int cntJob= jobs.size();
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    // 우선순위대로 작업을 출력해주는
    
    sort(jobs.begin(), jobs.end());
    reverse(jobs.begin(), jobs.end()); // 뒤에 있는 원소를 빼내기 위해 뒤집음
    // 미리 넣지 않고 시간 순서대로 넣는 것을 반복한다.
    while (!jobs.empty() || !pq.empty()){
        while ( !jobs.empty() && jobs.back().front()<=time) {
            // 넣을 수 있는 job가 있다면 계속 넣는다.
            pq.push(jobs.back());
            jobs.pop_back();
        } 
        
        if (pq.empty() && !jobs.empty()){
            // 넣을 job가 있는데 time이 흘러야 한다면
            time= jobs.back().front();
            continue;
        } else if (pq.empty()) break; // 진짜 없음
        
        tmp= pq.top().back();
        answer += (time+tmp) - pq.top().front(); // 평균 시간을 더해준다.
        pq.pop();
        time+=tmp;
    }
    
    return answer/cntJob;
}