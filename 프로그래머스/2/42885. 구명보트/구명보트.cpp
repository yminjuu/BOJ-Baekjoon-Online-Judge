#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 최대한 적은 개수의 보트를 사용해서 사람들을 태워야 한다
// 최대한 limit에 꽉 차게
int solution(vector<int> people, int limit) {
    int answer = 0; 
    
    sort(people.begin(), people.end()); 
    // 정렬 내림차순은?
    deque<long> deq(people.begin(), people.end());
        
    while (deq.size()>=2){
        int last = deq.back();
        deq.pop_back();
        
        if (deq.size() >=1 && last + deq.front()<=limit) {
            last += deq.front();
            deq.pop_front();
        }
        
        answer++;
    }
    
    if (deq.size()==1) {
        answer++;
    }
    
    return answer;
}