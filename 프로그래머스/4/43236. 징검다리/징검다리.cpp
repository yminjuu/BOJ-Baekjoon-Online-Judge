#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int g_dist, rockCnt;
vector<int> g_rocks;

// 해당 간격으로 만들 수 있는지 판단하여 반환
// dist는 각 지점 사이 거리의 최솟값 (이거보다 클 수 있음)
bool find(int dist){
    int currPos= 0;
    int removedRock= 0;
    
    for (int i=0; i<g_rocks.size(); i++){
        if (g_rocks[i]-currPos<dist){
            if (removedRock>= rockCnt) {
                // 더이상 제거 불가
                return false;
            }
            // 해당 바위를 제거한다
            removedRock++;
        } else {
            currPos= g_rocks[i];
        }
    }
    
    // 마지막 바위와 도착지 사이 거리 (빼먹음)
    if (g_dist - currPos < dist && removedRock==rockCnt){
        // 더 제거해야 하는데 제거 불가능하다면
        return false;
    }
    
    return true;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    g_dist = distance;
    g_rocks = rocks;
    rockCnt = n;
    
    int answer = 0;
    
    int s=0; int e= g_dist;
    while (s<=e){
        int mid = (s+e)/2;
        
        bool res= find(mid);
        
        if (res){
            // 간격 최솟값을 mid로 만들 수 있음
            answer = mid;
            s= mid+1; // 더 늘려봄
        } else {
            e= mid-1;
        }
    }
    
    return answer;
}