#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

struct Disk {
    int timeCost, requestTime, num;
};

struct cmp{
    bool operator() (Disk &a, Disk &b) {
    if (a.timeCost!= b.timeCost) return a.timeCost > b.timeCost; // false 여야 앞으로
    else if (a.requestTime != b.requestTime) return a.requestTime > b.requestTime;
    else return a.num > b.num;
    }
};

struct compare {
    bool operator() (vector<int> a, vector<int> b){
        if (a[0]!=b[0]) return a[0] < b[0]; // 요청 시점 
        else a[1] < b[1]; // 소요 시간
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    priority_queue<Disk, vector<Disk>, cmp> pq;
    
    int idx = 0; int time=0;
    while (!pq.empty() || idx < jobs.size()){
        // 1. 대기 큐에 하나도 없다면 대기 큐에 넣기
        if (pq.empty() && idx < jobs.size()) {
            time = jobs[idx][0];
            pq.push({jobs[idx][1], jobs[idx][0], idx++});
        }
        
        // 2. 실행하고 시간 흐름
        auto [timeCost, requestTime, num] = pq.top(); pq.pop();
        time += timeCost;
        answer += (time - requestTime);
        
        // 3. 시간 흐름에 따라 대기 큐에 들어갔어야 하는 거 다 넣음
        while (idx < jobs.size() && jobs[idx][0] <= time){
            pq.push({jobs[idx][1], jobs[idx][0], idx++});
        }
    }
    
    return floor((float)answer / jobs.size());
}