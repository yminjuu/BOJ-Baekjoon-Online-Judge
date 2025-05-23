#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
//     최소 힙에 넣는다
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());
    
    // 최종 목표는 top이 K 이상인 것
    while (pq.top()<K){
        //     개별 음식의 스코빌 지수가 7 이상 (성공) or pq size가 2 미만 (실패) => 종료
        if (pq.size()<2) { return -1;}
        
         //     음식을 섞고
        int tmp= pq.top(); pq.pop();
        pq.push(tmp + 2*pq.top());
        pq.pop();
        answer++;
    }
    
    return answer;
}