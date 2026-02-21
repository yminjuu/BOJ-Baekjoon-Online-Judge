#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>

using namespace std;

 int minLength= INT_MAX;
int st, en;
int gemsCnt=0;
vector<int> answer;
map<string, int> mp; // 해당 보석이 마지막으로 나온 인덱스를 저장하는 map
set<string> s;
vector<string> gGems;

void reduce(){
    while (st<en && mp[gGems[st]]!=1){
        mp[gGems[st]]--;
        st++;
    }
    if (gemsCnt== s.size() && minLength > (en-st)){
        minLength= en-st;
        answer[0]= st+1;
        answer[1]= en+1;
    }
}

vector<int> solution(vector<string> gems) {
    gGems = gems;
    
    s = set(gems.begin(), gems.end()); // set 초기화(기본 오름차순)
    
    for (auto& tmp: s){
        mp[tmp]= 0; // 개수 0으로 초기화
    }
    
    gemsCnt=0;
    answer.push_back(st); answer.push_back(en);
    for (int i=0; i<gems.size(); i++){
        en= i;
        if (mp[gems[i]]==0){
            // 아직 안 넣은 보석이라면
            mp[gems[i]]= 1;
            gemsCnt++;
            
            if (gemsCnt==s.size() && minLength > (en-st)){
                minLength = en-st;
                answer[0]= st+1;
                answer[1]= en+1;
            }
            // 현재의 start를 포기하는 방법을 사용한다.
            reduce();
        }
        // 이미 넣은 보석이라면
        else {
            mp[gems[i]]= mp[gems[i]]+ 1;
            // 만약 보석이 앞에 또 있으면 start를 줄일 수 있다.
            // 구간 줄이기 함수
            reduce();
        }
    }  
    
    return answer;
}