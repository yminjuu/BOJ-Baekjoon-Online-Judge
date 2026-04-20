#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0; 
    
    // 정렬 후 투포인터 사용
    sort(people.begin(), people.end());
    
    int s = 0; int e = people.size() - 1;
    while (s<=e){
        if (people[s] + people[e] <= limit){
            s++;
            e--;
        } else e--;
        answer++;
    }
    
    return answer;
}