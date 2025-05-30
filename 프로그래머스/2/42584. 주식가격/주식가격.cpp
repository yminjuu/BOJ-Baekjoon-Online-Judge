#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int,int> &a, pair<int,int> &b){
//         숫자가 큰 순서대로
        return a.first < b.first; // 더 뒤로 가는 기준 : 작아야 한다.
    }  
};

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for (int i=0; i<prices.size(); i++) answer.push_back(0);
    
    int i=0;
    for (; i<prices.size(); i++){
        while (!pq.empty() && prices[i] < pq.top().first){
            answer[pq.top().second] = i-pq.top().second;
            pq.pop();
        }
        pq.push(make_pair(prices[i], i));
    }
    
    i--;
    while (!pq.empty()){
        answer[pq.top().second] = i-pq.top().second;
        pq.pop();
    }
    return answer;
}