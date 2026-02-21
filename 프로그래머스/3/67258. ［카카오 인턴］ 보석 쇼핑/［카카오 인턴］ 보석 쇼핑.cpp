#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> s(gems.begin(), gems.end()); // set 초기화(기본 오름차순)
    
    map<string, int> mp;
    
    vector<int> answer = {1,  (int)gems.size()};
    
    int gemCnt=0; int minLength = INT_MAX;
    int start=0;
    for (int i=0; i<gems.size(); i++){
        mp[gems[i]]++; // 현재 보석 추가
        
        while (mp[gems[start]]>1){
            mp[gems[start]]--;
            start++;
        }
        
        if (mp.size()==s.size()){
            // 모든 보석을 다 모았다면
            if (minLength > i-start) {
                minLength= i-start;
                answer[0]= start+1;
                answer[1]= i+1;
            }
        }
    }
    
    return answer;
}