#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using p = pair<int, int>;

struct cmp1{
    bool operator () (p& a, p& b) const {
        return a.second < b.second; // pq는 반대
    }  
};

struct cmp2{
    // 강사 (인덱스, 상담 끝나는 시간)
    bool operator () (pair<int,int>& a, pair<int,int>& b) const {
        return a.second > b.second; // pq는 반대
    }  
};

int K,N;
int currMentor;
int mentor[6]; // 유형별 멘토수
vector<p> request[6]; // 유형별 요청건
int waitTimes[6][20]; // 유형별 멘토 늘렸을 때 대기 시간
priority_queue<p, vector<p>, cmp1> pq;

int getWaitTime(int type){
    int mentorCnt = mentor[type];
    vector<p> req = request[type];
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp2> mentors; // 현재 강사
    
    for (int i=0; i<mentorCnt; i++){
        mentors.push({i, 0}); // 모두 0에서 시작
    }
    
    int totalWaitTime = 0; int currReqIdx=0; 
    while (currReqIdx < req.size()){
       // 다음 상담 가능 강사
        auto [idx, currTime] = mentors.top(); mentors.pop();

        mentors.push({idx, max(currTime,req[currReqIdx].first) + req[currReqIdx].second});
        // 대기 시간 반영 (만약 기다렸다면)
        if (req[currReqIdx].first < currTime) {
            totalWaitTime += (currTime-req[currReqIdx].first);
        }
        currReqIdx++;
    }
    return totalWaitTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    K=k; N=n; currMentor= k;
    fill(&mentor[0], &mentor[5]+1, 1); // 처음엔 1명으로 시작
    
    // 초기 request 배열에 넣기
    for (int i=0; i<reqs.size(); i++){
        request[reqs[i][2]].push_back({reqs[i][0], reqs[i][1]});
    }
    
    // 멘토 1명에서 2명 늘릴 때 대기시간 감소 폭 구하기
    for (int i=1; i<=k; i++){
        int waitTime1 = getWaitTime(i); // 1일 때 대기 시간
        waitTimes[i][1] =waitTime1; 
        
        mentor[i]= 2;
        int waitTime2= getWaitTime(i); // 2일 때의 대기 시간
        waitTimes[i][2]= waitTime2;
        
        mentor[i]=1; // 되돌림
        
        pq.push({i, waitTime1- waitTime2});
    }
    
    // currMentor == n이 될 때까지 강사 수를 늘린다
    while (currMentor < n) {
        auto [type, currWaitTime] = pq.top(); pq.pop();
        
        mentor[type]++; // 멘토 1명 늘리기
        
        mentor[type]++; // 일시적으로 늘림
        waitTimes[type][mentor[type]] = getWaitTime(type);
        mentor[type]--; // 복구
        
        // 다시 넣는다
        pq.push({type, waitTimes[type][mentor[type]] - waitTimes[type][mentor[type]+1]});
        
        currMentor++; // 늘릴 수 있을 때까지
    }
    
    // 현재 멘토 수에 따른 대기 시간을 구한다
    int totalWaitTime=0;
    for (int i=1; i<=k; i++){
        totalWaitTime += getWaitTime(i);
    }
    
    return totalWaitTime;
}