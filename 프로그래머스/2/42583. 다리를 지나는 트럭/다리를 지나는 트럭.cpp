#include <string>
#include <vector>
#include <deque>

using namespace std;

bool possible(int bridge_length, int weight, int currentWeight, int currentCnt){
    if (currentCnt > bridge_length || currentWeight > weight) return false;
    else return true;
}

// 제약 사항 1) 다리에 오를 수 있는 최대 트럭의 개수: bridge_length
// 제약 사항 2) 다리에 오를 수 있는 트럭들의 무게: weight (완전히 다리에 올라야 인정)
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    deque<pair<int,int>> deq; // weight, 들어간 시간
    int weightSum=0, cnt=0, time=1;
    // 제약 사항을 위반하지 않는 한 순서대로 들여보내고,
    // 가장 마지막 트럭의 소요 시간을 측정하면 된다.
    
    for (int i=0; i<truck_weights.size(); i++){
        while (!possible(bridge_length, weight, weightSum+truck_weights[i], cnt+1)){
            // 넣을 수 없는 경우 가능할 때까지 앞의 원소를 빼며 time을 변경
            cnt--; weightSum-=deq.front().first; 
            time= deq.front().second+bridge_length;
            deq.pop_front();
        }
            // 넣을 수 있는 경우 넣고
            cnt++; weightSum+=truck_weights[i];
            deq.push_back(make_pair(truck_weights[i], time));
            // 다음 time을 1 증가시킨 뒤, 뺄 수 있다면 가장 앞의 원소를 빼야 한다.
            if (deq.front().second + bridge_length <= ++time && i!=truck_weights.size()-1) {
                cnt--; weightSum-=deq.front().first;
                deq.pop_front();
            }
    }
    
    return deq.back().second + bridge_length;
    // 마지막 원소까지 처리 완료해야 됨
}