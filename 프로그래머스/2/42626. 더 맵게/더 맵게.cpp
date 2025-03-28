#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
//     최소 힙에 넣는다
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i< scoville.size(); i++){
        pq.push(scoville.at(i));
    }
    
    while (!pq.empty()){
        //     개별 음식의 스코빌 지수가 7 이상 (성공) or pq size가 2 미만 (실패) => 종료
        if (pq.top()>=K) return answer;
        if (pq.size()<2) { return -1;}
        
         //     음식을 섞고
        int tmp= pq.top(); pq.pop();
        tmp+= 2*pq.top(); pq.pop();
        answer++;
        
        //     다시 heap에 추가
        pq.push(tmp);      
    }
}