#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while (pq.top() < K){
        if (pq.size()<2) {
            answer = -1;
            break;
        }
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        
        int newScoville = first + second * 2;
        pq.push(newScoville);
        answer++;
    }
    
    return answer;
}