#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using p = pair<int, int>;
vector<p> route;

// 교집합들의 집합을 만든다.
// 조금이라도 겹치는 구간이 있으면 그 구간을 포함하도록 구간을 줄인다
int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    for (int i=0; i<routes.size(); i++){
        route.push_back({routes[i][0], routes[i][1]});
    }
    
    sort(route.begin(), route.end(), [](p a, p b){
        return a.first < b.first;
    }); // 이 문법 기억할 것
    
    int s = -30001; int e = -30001;
    for (int i=0; i<route.size(); i++){
        int newS = route[i].first; int newE = route[i].second;
        
        if (s<=newS && newS<=e) {
            s= newS;
            e= min(e, newE);
        } else {
            // 교집합이 없다면 answer 추가 후 범위 추가
            answer++;
            s= newS;
            e= newE;
        }
    }
        
    return answer;
}