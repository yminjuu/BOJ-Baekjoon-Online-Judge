#include <string>
#include <vector>
#include <deque>

using namespace std;

struct Truck {
    int time, weight;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // {끝나는 시간, 무게}를 저장
    deque<Truck> deq;
    
    // 큐 초기화
    for (int i=0; i< bridge_length; i++){
        deq.push_back({0,0}); 
    }
    
    int currTime=0; int currWeight=0; int truckIdx=0;
    while (truckIdx!= truck_weights.size()){
        currTime++;
        currWeight -= deq.front().weight;
        deq.pop_front();
        
        if (currWeight + truck_weights[truckIdx] <= weight){
            currWeight += truck_weights[truckIdx];
            deq.push_back({currTime+bridge_length, truck_weights[truckIdx++]});
        } else deq.push_back({currTime+bridge_length, 0});
        
    }
    currTime = deq.back().time;
    
    return currTime;
}