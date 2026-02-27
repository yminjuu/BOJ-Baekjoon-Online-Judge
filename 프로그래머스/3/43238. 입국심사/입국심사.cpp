#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end()); // 오름차
    
    long long left= 1;
    long long right = (long long)times[times.size()-1] * n; // 가장 느린 사람이 전부 함
    
    while (left < right) {
        long long mid = (left+right)/2;
        long long totalPeople= 0;
        
        // mid 시간 안에 할 수 있는지 확인
        for (auto t : times){
            totalPeople += (mid / t); // 적게 걸리는 사람부터 전부 채움
            if (totalPeople>=n) break;
        }
        
        if (totalPeople>=n) {
            // 가능함. 더 줄여봄
            right= mid;
        } else {
            // 불가능
            left= mid+1;
        }
    }
    
    return right;
}