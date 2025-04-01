#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0; // 배의 개수
    sort(people.begin(), people.end(), greater<>()); // 내림차순 정렬
    deque<int> deq; // 앞뒤가 다 뚫려있는
    
    for (int i=0; i< people.size(); i++) deq.push_back(people[i]);
    
    while (!deq.empty()){
        if (deq.size()==1) {deq.pop_front(); answer++; break;}
        if (deq.front()+deq.back()<=limit) {
            deq.pop_front(); deq.pop_back();
        } else {
            deq.pop_front();
        }
        answer++;
    }
    
    return answer;
}